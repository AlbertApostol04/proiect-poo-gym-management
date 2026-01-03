#pragma once


#include<string>

#include "Abonament.h"

class AbonamentPerioada:public Abonament
{private:


    int intrariEfectuate;
    static const double pretFix;

public:

    AbonamentPerioada();
    AbonamentPerioada(int zile, bool stud);


    const std::string& getTipAb() const;

    void setIntrariEfectuate(int a);

    double oferte(int zile);

    bool permiteIntrare() const override;
    void checkIn() override;



};