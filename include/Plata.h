#pragma once
#include <string>

class Plata
{
protected:
    double suma;
public:

    Plata();
    explicit Plata(double suma);
    virtual ~Plata() = default;

    double getSuma() const;

    virtual double proceseaza() = 0;

};
