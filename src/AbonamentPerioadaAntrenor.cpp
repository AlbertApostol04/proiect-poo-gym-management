#include "AbonamentPerioadaAntrenor.h"


const double AbonamentPerioadaAntrenor::pretPeSedinta=60.0;
const int AbonamentPerioadaAntrenor::durataSedeinta=60;

AbonamentPerioadaAntrenor::AbonamentPerioadaAntrenor()
    : AbonamentPerioada(0,false)
{
    pret= PretAbonamentStudent(pretPeSedinta*sedinte,false);
    tipAb = "Abonament cu nelimitat + antrenor personal";
    sedinte= 0;
}


AbonamentPerioadaAntrenor::AbonamentPerioadaAntrenor(int perioada,int sedinte1, bool stud)
    : AbonamentPerioada(perioada,stud)
{
    pret = PretAbonamentStudent(pretPeSedinta*sedinte,stud);
    tipAb = "Abonament cu nelimitat + antrenor personal";
    sedinte = sedinte1;

}

void AbonamentPerioadaAntrenor::setNumeAntrenor(const std::string& nume)
{
    numeAntrenor=nume;
}

const std::string& AbonamentPerioadaAntrenor::getNumeAntrenor() const
{
    return numeAntrenor;
}

const int AbonamentPerioadaAntrenor::getSedinte() const
{
    return sedinte;
}
