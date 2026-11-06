// deck.cpp
// Ensc 251 Project: UnoDeck class implementation

#include "deck.hpp"
#include <algorithm>    // std::shuffle
#include <random>       // std::mt19937, std::random_device
#include <stdexcept>    // std::invalid_argument
#include <string>       // std::to_string

// How UnoCard encodes its cards (see unoCard.cpp):
//   colour: 0 Blue, 1 Yellow, 2 Green, 3 Red, 4 Colourless (wild)
//   value:  0-9 numbers, 10 Skip, 11 Reverse, 12 +2, 13 Wild, 14 Wild +4
static const int NUM_COLOURS = 4;
static const int WILD_COLOUR = 4;
static const int LAST_COLOURED_VALUE = 12;
static const int WILD = 13;
static const int WILD_DRAW_FOUR = 14;
static const int DECK_SIZE = 108;

UnoDeck::UnoDeck()
{
    cards.reserve(DECK_SIZE);    // room for a full deck; the deck itself starts empty
}

void UnoDeck::reset()
{
    cards.clear();

    for (int colour = 0; colour < NUM_COLOURS; colour++)
    {
        cards.push_back(UnoCard(colour, 0));            // only one 0 per colour

        // 1-9, Skip, Reverse and +2 each appear twice per colour
        for (int value = 1; value <= LAST_COLOURED_VALUE; value++)
        {
            cards.push_back(UnoCard(colour, value));
            cards.push_back(UnoCard(colour, value));
        }
    }

    // Four Wild and four Wild +4 (colourless)
    for (int i = 0; i < 4; i++)
    {
        cards.push_back(UnoCard(WILD_COLOUR, WILD));
        cards.push_back(UnoCard(WILD_COLOUR, WILD_DRAW_FOUR));
    }
}

void UnoDeck::replaceDeckWith(const std::vector<UnoCard>& newCards)
{
    cards = newCards;    // vector assignment makes its own copy of every card
}

bool UnoDeck::isEmpty() const
{
    return cards.empty();
}

int UnoDeck::size() const
{
    return static_cast<int>(cards.size());
}

void UnoDeck::shuffle()
{
    // One random engine for the whole program, seeded from the OS once.
    static std::mt19937 rng(std::random_device{}());
    std::shuffle(cards.begin(), cards.end(), rng);
}

UnoCard UnoDeck::drawCard()
{
    if (isEmpty())
        throw std::invalid_argument("Cannot draw a card since there are no cards in the deck");

    UnoCard top = cards.back();    // save the top card
    cards.pop_back();              // remove it from the deck
    return top;
}

std::vector<UnoCard> UnoDeck::drawCard(int n)
{
    if (n < 0)
        throw std::invalid_argument("Must draw positive cards but tried to draw "
                                    + std::to_string(n) + " cards.");

    if (n > size())
        throw std::invalid_argument("Cannot draw " + std::to_string(n)
                                    + " cards since there are only "
                                    + std::to_string(size()) + " cards.");

    std::vector<UnoCard> drawn;
    drawn.reserve(n);
    for (int i = 0; i < n; i++)
        drawn.push_back(drawCard());

    return drawn;
}
