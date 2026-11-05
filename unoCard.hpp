#ifndef UNOCARD_HPP
#define UNOCARD_HPP

#include <ostream>

class UnoCard{
private:
    int colourVal;
    int value;
public:
    UnoCard();
    UnoCard(int c, int v);

    int getColour() const;
    void setColour(const int c);

    int getValue() const;
    void setValue(const int v);

    bool isValid() const;
    bool canPlayOn(const UnoCard& ctop, int activeColour) const;
    bool isWild() const;
    void printColour(std::ostream& outs) const;
    void printValue(std::ostream& outs) const;

};

#endif