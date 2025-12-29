#pragma once
#include <string>
#include<ostream>


class Client{

private:
    std::string nume;
    std::string email;
    std::string nrTel;
    int idClient;
    static int generatorId;
public:


    Client();
    Client(const std::string& nume,const std::string& email,const std::string& nrTel);
    int getIdClient() const;

    const std::string& getNume() const;
    const std::string& getEmail() const;
    const std::string& getNrTel() const;

    void setNume(const std::string& Nume);
    void setEmail(const std::string& Email);
    void setNrTel(const std::string& nrtel);

};

std::ostream& operator<<(std::ostream& out, const Client& c);