#pragma once
#include <string>
#include<iostream>

class Abonament;

class Client{

private:
    std::string nume;
    std::string email;
    std::string nrTel;
    int idClient;
    static int generatorId;

    Abonament* abonament;

public:



    Client();
    Client(const std::string& nume,const std::string& email,const std::string& nrTel);
    int getIdClient() const;

    const std::string& getNume() const;
    const std::string& getEmail() const;
    const std::string& getNrTel() const;
    const Abonament* getAbonament();


    void setNume(const std::string& Nume);
    void setEmail(const std::string& Email);
    void setNrTel(const std::string& nrtel);
    void setAbonament(Abonament* a);

    bool areAbonament() const;

    Client& operator=(const Client& c);
};

std::ostream& operator<<(std::ostream& out,const Client& c);
std::istream& operator>>(std::istream& in, Client& c);

