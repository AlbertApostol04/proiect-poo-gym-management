#include "AbonamentCuIntrari.h"
#include<iostream>

const double AbonamentCuIntrari::pretFix=130;

AbonamentCuIntrari::AbonamentCuIntrari()
{
    nrIntrariRamase=8;
    zileRamase=valabilitateNormala;
    pret=pretFix;
    student=false;
    tipAb="Abonament cu 8 intrari";

}

AbonamentCuIntrari::AbonamentCuIntrari(bool stud)
{
    nrIntrariRamase=8;
    zileRamase=valabilitateNormala;
    student=stud;
    pret=PretAbonamentStudent(pretFix,stud);
    tipAb="Abonament cu 8 intrari";
}


void AbonamentCuIntrari::setNrIntariRamase(int nr)
{
    nrIntrariRamase=nr;
}

int AbonamentCuIntrari::getNrIntrariRamase() const
{
    return nrIntrariRamase;
}


bool AbonamentCuIntrari::permiteIntrare() const
{
    return (zileRamase >0) && (nrIntrariRamase >0);


}

void AbonamentCuIntrari::checkIn()
{
    if (!permiteIntrare())
    {
        std::cout<<"Abonamentul dumneavoastra nu mai este valabil\n";
    }
    else
    {
        setNrIntariRamase(nrIntrariRamase-1);
        std::cout<<"Spor la antrenament!\n";
    }

}


