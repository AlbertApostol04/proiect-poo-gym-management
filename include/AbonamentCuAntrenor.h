#pragma once
#include "AbonamentCuIntrari.h"



class AbonamentCuAntrenor: public AbonamentCuIntrari
{
private:

    std::string numeAntrenor;
    static const double pretPeSedinta;
    static const int durataSedeinta;


public:
    AbonamentCuAntrenor();
    AbonamentCuAntrenor(int nr, bool stud);


    const std::string& getNumeAntrenor() const;


    void setNumeAntrenor(const std::string& nume);

};
