#include "AbonamentPerioada.h"
#include<iostream>

const double AbonamentPerioada::pretFix=170;

AbonamentPerioada::AbonamentPerioada()
{
    pret=pretFix;
    intrariEfectuate=0;
    zileRamase=valabilitateNormala;
    student=false;
    intrariEfectuate=0;
    tipAb="Abonament Nelimitat";
}

double AbonamentPerioada::oferte(int zile)
{
    if (zile == 1)
        return 20.0;
    if (zile == 7)
        return 60.0;
    if (zile == 14)
        return 100.0;
    if (zile == 28)
        return pretFix;
    throw std::invalid_argument("Numarul de zile este  invalid!Permise:1, 7, 14, 28");
}

AbonamentPerioada::AbonamentPerioada(int zile, bool stud)
{
    student=stud;
    zileRamase=zile;
    intrariEfectuate=0;
    pret=PretAbonamentStudent(oferte(zile),stud);
    tipAb="Abonament Nelimitat";

}


bool AbonamentPerioada::permiteIntrare() const
{
    return (zileRamase >0);

}

void AbonamentPerioada::checkIn()
{
    if (!permiteIntrare())
    {
        std::cout<<"Abonamentul dumneavoastra nu mai este valabil\n";
    }
    else
    {

        std::cout<<"Spor la antrement!\n";
    }
}


