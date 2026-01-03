#pragma once
#include<string>

class Abonament{

protected:

    double pret;
    int zileRamase;
    bool student;
    static const int valabilitateNormala;
    std::string tipAb;


public:

    Abonament();
    Abonament (bool stud);
    virtual ~Abonament();


    virtual bool permiteIntrare() const = 0;
    virtual void checkIn() = 0;


    const std::string& getTipAb() const;

    double getPret() const;
    int getZileRamase() const;

    static double PretAbonamentStudent(double pretNormal, bool stud);

};