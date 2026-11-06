// deck.hpp
// Ensc 251 Project: UnoDeck class header file
//
// A deck of UnoCards. The back of the vector is the top of the deck, so
// drawing removes from the back (same idea as cards[--cardsInDeck] in the
// Java version).

#ifndef DECK_HPP
#define DECK_HPP

#include <vector>
#include "unoCard.hpp"

class UnoDeck {
private:
    std::vector<UnoCard> cards;   // back of the vector = top of the deck

public:
    // Precondition: none
    // Postcondition: Creates an EMPTY deck. Call reset() to fill it with the 108 Uno cards.
    UnoDeck();

    // Precondition: none
    // Postcondition: Throws away whatever was in the deck and rebuilds a full, ordered
    // (unshuffled) 108-card Uno deck:
    //   per colour (Blue, Yellow, Green, Red): one 0, two each of 1-9, Skip, Reverse, +2  (25 cards)
    //   plus 4 Wild and 4 Wild +4 (colourless)                                            (8 cards)
    void reset();

    // Precondition: none
    // Postcondition: The deck now holds exactly the cards in newCards (same order);
    // the last card in newCards becomes the top. Used to turn the discard pile back into a deck.
    void replaceDeckWith(const std::vector<UnoCard>& newCards);

    // Precondition: none
    // Postcondition: Returns true if there are no cards left in the deck; deck is unchanged
    bool isEmpty() const;

    // Precondition: none
    // Postcondition: Returns the number of cards in the deck; deck is unchanged
    int size() const;

    // Precondition: none
    // Postcondition: The cards currently in the deck are put in a random order
    void shuffle();

    // Precondition: deck must not be empty
    // Postcondition: Removes the top card from the deck and returns it.
    // Throws std::invalid_argument if the deck is empty.
    UnoCard drawCard();

    // Precondition: 0 <= n <= size()
    // Postcondition: Removes the top n cards from the deck and returns them (first drawn first).
    // Throws std::invalid_argument if n is negative or larger than the number of cards left.
    std::vector<UnoCard> drawCard(int n);
};

#endif // DECK_HPP
