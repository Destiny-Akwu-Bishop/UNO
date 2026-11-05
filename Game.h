// Ensc 251 Project: Uno Gameplay class header file
// Destiny Akwu-Bishop, Elliot Yang, Bruno Kang, Quinton Ho
//
// This Class is responsible for the gameplay of uno. In charge of the rules, regulation, and flow of the game.

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "unoCard.hpp"
#include "UnoDeck.h"
#include "Exceptions.hpp"

class Game {
private:
    int currentPlayer; // current player
    std::vector<std::string> playerIds; // array of player names

    unoDeck deck; // deck of cards

    std::vector<std::vector<unoCard>> playerHands; // array of player hands, has to be like this since every particular 
    // player hand is its own array and we are keeping track of that 
    
    std::vector<unoCard> stockpile; // array of cards in the stockpile, happens when you place down a card

    unoCard::colourVal validColor;
    unoCard::value validValue;

public:
    // Precondition: none
    // Postcondition: Allows you to know the direction of gameplay, counter-clockwise or clockwise
    bool gameDirection();

    // Precondition: has to be a valid string vector of player IDs
    // Postcondition: Puts whatever is in pids into playerIds and draws 7 cards from the deck that is added to the playerHand variable, 
    // done via for loop so as to take every hand
    Game(std::vector<std::string> pids);

    // Precondition: game must be a valid initialized Game object
    // Postcondition: Starts the game, looks for validity in each card taken from the deck
    // and looks at special cards as well
    void start(Game game);

    // Precondition: validColor and validValue must be initialized and valid
    // Postcondition: Returns a new UnoCard using these values; object state is unchanged
    unoCard getTopCard() const;

    // Precondition: validColor and validValue must be initialized and valid
    // Postcondition: Returns a new ImageIcon corresponding to the top card; object state is unchanged
    ImageIcon getTopCardImage() const;

    // Precondition: none
    // Postcondition: Returns true if the game is over (i.e., if any player has no cards left)
    bool isGameOver() const;

    // Precondition: currentPlayer must be initialized and valid
    // Postcondition: Returns the ID of the current player; object state is unchanged
    std::string getCurrentPlayerId() const;

    // Precondition: playerIndex must be a valid index in the playerIds vector
    // Postcondition: Returns the ID of the player at the specified index; object state is unchanged
    std::string getPlayerId(int playerIndex) const;

    // Precondition: none
    // Postcondition: Returns a vector of all player IDs; object state is unchanged
    std::vector<std::string> getPlayerIds() const;

    // Precondition: playerIndex must be a valid index in the playerHands vector
    // Postcondition: Returns a vector of UnoCards representing the hand of the player at the specified index
    std::vector<unoCard> getPlayerHand(int playerIndex) const;

    // Precondition: pid must be a valid player ID
    // Postcondition: Returns the number of cards in the hand of the player with the specified ID; object state is unchanged
    int getPlayerHandSize(std::string pid) const;

    // Precondition: pid must be a valid player ID, and cardIndex must be a valid index in the player's hand
    // Postcondition: Returns the UnoCard at the specified index in the hand of the player
    unoCard getPlayerCard(std::string pid, int cardIndex) const;

    // Precondition: pid must be a valid player ID
    // Postcondition: Returns true if the player with the specified ID has no cards left
    bool hasEmptyHand(std::string pid) const;

    // Precondition: card must be a valid UnoCard
    // Postcondition: Returns true if the specified card can be played on the current top card, based on color or value; object state is unchanged
    bool validCardPlay(unoCard card) const;

    // Precondition: pid must be a valid player ID
    // Postcondition: Checks if it's the turn of the player with the specified ID; throws an exception if invalid
    void checkPlayerTurn(std::string pid);

    // Precondition: pid must be a valid player ID
    // Postcondition: Draws a card from the deck and adds it to the hand of the player with the specified ID; updates the game state accordingly
    void submitDraws(std::string pid);

    // Precondition: color must be a valid UnoCard::Color
    // Postcondition: Sets the validColor to the specified color; object state is updated
    void setCardColor(unoCard::colourVal color);

    // Precondition: pid must be a valid player ID, card must be a valid UnoCard, and declaredColor must be a valid UnoCard::Color
    // Postcondition: Submits the specified card for the player with the specified ID, checks for validity, and updates the game state accordingly; throws exceptions if the submission is invalid
    void submitPlayerCard(const std::string& pid, const unoCard& card, unoCard::colourVal declaredColor);
};

#endif // GAME_H
