#include<iostream>
#include"PlataCard.h"
#include<stdexcept>


PlataCard::PlataCard()
{
    suma=0;
    cardValid=true;
}

PlataCard::PlataCard(double s)
{
    suma=s;
    setCardValid(true);
}

bool PlataCard::getCardValid() const
{
    return cardValid;
}

void PlataCard::setCardValid(bool v)
{
    cardValid = v;
}


double PlataCard::proceseaza()
{

        if (!getCardValid())
            throw std::runtime_error("Card respins.");
        else
        {
            std::cout<<"Plata acceptata\n";
            return 0.0;
        }

}