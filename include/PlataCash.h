#pragma once
#include "Plata.h"
#include<string>

class PlataCash: public Plata
{
private:
    double baniPrimiti;

public:

    PlataCash();
    PlataCash(double suma, double baniPrimiti);

    double getBaniPrimiti() const ;
    void setBaniPrimiti(double s);

    double proceseaza() override;
};