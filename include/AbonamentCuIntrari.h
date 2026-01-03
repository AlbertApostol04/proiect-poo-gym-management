#pragma once

#include<string>

#include "Abonament.h"

class AbonamentCuIntrari:public Abonament
{
private:

    int nrIntrariRamase;
    static const double pretFix;




public:

    AbonamentCuIntrari();
    AbonamentCuIntrari(bool stud);

    void setNrIntariRamase(int nr);

    int getNrIntrariRamase() const;



    bool permiteIntrare() const override;
    void checkIn() override;

};