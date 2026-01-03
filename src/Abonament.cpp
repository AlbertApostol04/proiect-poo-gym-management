#include "Abonament.h"

const int Abonament::valabilitateNormala = 30;

Abonament::Abonament()
{
    student=false;
    zileRamase=28;
    pret=0.0;


}


Abonament::Abonament(bool stud)
{

    this->student=stud;
    zileRamase=28;
    pret=0.0;

}

double Abonament::PretAbonamentStudent(double pret1, bool stud)
{
    if (stud)
        return pret1*2.0/3.0;
    else return pret1;
}

int Abonament::getZileRamase() const
{
    return zileRamase;
}

Abonament::~Abonament() = default;

double Abonament::getPret() const
{
    return pret;
}

const std::string& Abonament::getTipAb() const
{
    return tipAb;
}

