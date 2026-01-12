#include<string>
#include "AbonamentPerioada.h"

class AbonamentPerioadaAntrenor: public AbonamentPerioada
{
private:

    std::string numeAntrenor;
    static const double pretPeSedinta;
    static const int durataSedeinta;
    int sedinte;


public:
    AbonamentPerioadaAntrenor();
    AbonamentPerioadaAntrenor(int perioada,int sedinte, bool stud);


    const std::string& getNumeAntrenor() const;


    void setNumeAntrenor(const std::string& nume);

    const int getSedinte()const;

};
