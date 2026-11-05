#include <iostream>
#include <string>
#include "unoCard.hpp"
using std::cout;
using std::endl;

//default constructor for Card
UnoCard::UnoCard(){
    colourVal = 0;
    value = 0;
}
//constructor for Card
UnoCard::UnoCard(int c, int v){
    colourVal = c;
    value = v;
}
//getter and setter of colour
int UnoCard::getColour() const{
    return colourVal;
}

void UnoCard::setColour(const int c){
    colourVal = c;
}
//getter and setter of value
int UnoCard::getValue() const{
    return value;
}

void UnoCard::setValue(const int v){
    value = v;
}

//Checks the validity of the card's value and colourval
bool UnoCard::isValid() const{
    if (colourVal >= 0 && colourVal <= 4){
        if (value >= 0 && value <= 14 ){
            if (colourVal <= 3 && value <= 12){
                    return true;
            } else if (colourVal == 4 && value >= 13){
                return true;
            } else{
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}

//checks if the current card can be placed on top of the top card of the pile
bool UnoCard::canPlayOn(const UnoCard& ctop, int activeColour) const{
//Precondition: Card Value and Colour are valid.
//Postcondition: returns true if a either the value or the colour of a card matches or is a wild card.
//               returns false if neither the value or the colour matches or if the card is not a wild card.

    if (isValid() && ctop.isValid()){
        if (activeColour > 3 || activeColour < 0){
            return false;
        }
        if (getColour() == 4){
            return true;
        } 
        else if (getValue() == activeColour)
            return true;
        else if (getValue() == ctop.getValue())
            return true;
        else
            return false;
    } else 
        return false;
}

//checks if your current card is a wild card
bool UnoCard::isWild() const{
//Precondition: Card Value and Colour are valid.
//Postcondition: returns true if card is a while card, returns false if it is not.

    if (isValid()){
        if (colourVal == 4)
            return true;
        else 
            return false;
    } else 
        return false;
}

//prints the colour of the card
void UnoCard::printColour(std::ostream& outs) const{
//Precondition: Card Value and Colour are valid.
//Postcondition: Outputs the Colour of the card as a string and if it doesn't pass precondition,
//               then it outputs an invalid message and returns.

    std::string colourName [] = {"Blue", "Yellow", "Green", "Red", "Colourless"};

    if (isValid()){
        outs << "Colour: " << colourName[colourVal] << endl;
    } else {
        outs << "Invalid Card. Cannot Print Colour." << endl;
        return;
    }
}

//prints the value of the card
void UnoCard::printValue(std::ostream& outs) const{
//Precondition: Card Value and Colour are valid
//Postcondition: Outputs the Value of the card as a string and if it doesn't pass precondition,
//               then it outputs an invalid message and returns.

    std::string cardValue[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8",
                            "9", "Skip", "Reverse", "+2", "Wild", "Wild +4"};
    
    if (isValid()){
        outs << "Card: " << cardValue[value] << endl;
    } else{
        outs << "Invalid Card. Cannot Print Value." << endl;
        return;
    }
}