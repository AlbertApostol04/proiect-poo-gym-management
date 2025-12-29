#include "Client.h"



int Client::generatorId=1;
Client::Client(): nume(""),email(""),nrTel(""),idClient(generatorId++){}

Client::Client(const std::string& nume, const std::string& email, const std::string& telefon):
nume(nume),email(email),nrTel(telefon),idClient(generatorId++){}

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

std::ostream& operator<<(std::ostream& out,const Client& c)
{
   out<< c.getIdClient()<<" "<<c.getEmail()<<" "<<c.getNume()<<" "<<c.getNrTel();
}





