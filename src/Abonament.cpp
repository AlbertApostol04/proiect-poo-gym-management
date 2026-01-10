#include "Abonament.h"


const int Abonament::valabilitateNormala = 28;

Abonament::Abonament()
{
    student=false;
    zileRamase=valabilitateNormala;
    pret=0.0;

}

Abonament::Abonament(bool stud)
{

    this->student=stud;
    zileRamase=valabilitateNormala;
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

