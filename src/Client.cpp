#include "Client.h"
#include <stdexcept>


int Client::generatorId=1;
Client::Client(): nume(""),email(""),nrTel(""),idClient(generatorId++),abonament(nullptr){}

Client::Client(const std::string& nume, const std::string& email, const std::string& telefon):
nume(nume),email(email),nrTel(telefon),idClient(generatorId++),abonament(nullptr){}

int Client::getIdClient() const{
    return idClient;
}

const std::string& Client::getNume() const
{
    return nume;
}


const std::string& Client::getEmail() const
{
    return email;
}

const std::string& Client::getNrTel() const
{
    return nrTel;
}

const Abonament* Client::getAbonament()
{
    return abonament;
}


void Client::setNume(const std::string& Nume)
{
    this->nume=Nume;
}

void Client::setEmail(const std::string& Email)
{
    this->email=Email;
}

void Client::setNrTel(const std::string& telefon)
{
    this->nrTel=telefon;
}

void Client::setAbonament(Abonament* a)
{
    abonament=a;
}


std::ostream& operator<<(std::ostream& out,const Client& c)
{
   out<<"Id client:"<<c.getIdClient()
    <<" | "<<"Nume: "<<c.getNume()
    <<" | "<<"Email: "<<c.getEmail()
    <<" | "<<"Numar de telefon: "<<c.getNrTel();

    return out;
}

std::istream& operator>>(std::istream& in, Client& c)
{
    std::string nume, email, tel;

    std::getline(in >> std::ws, nume);
    std::getline(in, email);
    std::getline(in, tel);

    c.setNume(nume);
    c.setEmail(email);
    c.setNrTel(tel);

    return in;
}

bool Client::areAbonament() const
{
    return abonament!= nullptr;
}

Client& Client::operator=(const Client& c)
{
    if (this == &c) return *this;

    nume=c.nume;
    email = c.email;
    nrTel = c.nrTel;

    abonament=c.abonament;

    return *this;
}








