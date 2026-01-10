#include "Antrenor.h"
#include<stdexcept>
#include<istream>
#include<ostream>


const int Antrenor::nrMaxClienti=5;
int Antrenor::idGenerator=1;

Antrenor::Antrenor(): numeAntrenor(""),nrTel(""),idAntrenor(idGenerator++),nrClientiCurenti(0),clientiId(new int[nrMaxClienti])
{
    for (int i=0;i < nrMaxClienti;i++)
        clientiId[i] = 0;
}

Antrenor::Antrenor(const std::string& nume,const std::string& nrTel):
numeAntrenor(nume),nrTel(nrTel),idAntrenor(idGenerator++),nrClientiCurenti(0),clientiId(new int[nrMaxClienti])
{

    for (int i=0;i < nrMaxClienti;i++)
        clientiId[i] = 0;

}

Antrenor::Antrenor(const Antrenor& a):
numeAntrenor(a.numeAntrenor),nrTel(a.nrTel), idAntrenor(a.idAntrenor),nrClientiCurenti(a.nrClientiCurenti),clientiId(new int[nrMaxClienti])
{
    for (int i=0;i < nrMaxClienti;i++)
        clientiId[i] = a.clientiId[i];
}

Antrenor::~Antrenor()
{
    delete[] clientiId ;
    clientiId=nullptr;
}


int Antrenor::getNrClienti() const
{
    return nrClientiCurenti;
}

int Antrenor::getMaxClienti() const
{
    return nrMaxClienti;
}
int Antrenor::getIdAntrenor() const
{
    return idAntrenor;
}
const std::string& Antrenor::getNume() const
{
    return numeAntrenor;
}
const std::string& Antrenor::getNrTel() const
{
    return nrTel;
}

bool Antrenor::disponibil() const
{
    return nrClientiCurenti<nrMaxClienti;
}

int Antrenor::locuriLibere() const
{
    return nrMaxClienti-nrClientiCurenti;
}

void Antrenor::setNumeAntrenor(const std::string& Nume)
{
    numeAntrenor=Nume;
}


void Antrenor::setNrTel(const std::string& telefon)
{
    nrTel=telefon;
}

void Antrenor::alocaClient(int idClient)
{
    if (idClient <= 0)
        throw std::runtime_error("Id-ul acesta este invalid.");

    if (clientiId == nullptr)
        throw std::runtime_error("Lista nu este initalizata");

    if (nrClientiCurenti >= nrMaxClienti)
        throw std::runtime_error("Antrenorul ales nu mai are locuri disponibile");


    for (int i=0; i < nrClientiCurenti;i++)
        if (clientiId[i]==idClient)
            throw std::runtime_error("Clientul este deja inscris la acest antrenor");

    clientiId[nrClientiCurenti]=idClient;
    nrClientiCurenti+=1;

}

Antrenor& Antrenor::operator=(const Antrenor& a)
{
    if (this == &a)
        return *this;

    numeAntrenor=a.numeAntrenor;
    nrTel=a.nrTel;
    idAntrenor=a.idAntrenor;
    nrClientiCurenti=a.nrClientiCurenti;

    int* nou=new int[nrMaxClienti];
    for (int i=0;i < nrMaxClienti;i++)
        nou[i] = a.clientiId[i];

    delete[] clientiId;
    clientiId=nou;

    return *this;
}

std::istream& operator>>(std::istream& in, Antrenor& c)
{
    std::string nume, tel;

    std::getline(in >> std::ws, nume);
    std::getline(in, tel);

    c.setNumeAntrenor(nume);
    c.setNrTel(tel);

    return in;
}

Antrenor& Antrenor::operator+=(int idClient)
{
    alocaClient(idClient);
    return *this;
}


std::ostream& operator<<(std::ostream& out, const Antrenor& a)
{
    out<<"Id antrenor: "<<a.getIdAntrenor()
    <<" | Nume: " <<a.getNume()
    <<" | Tel: " << a.getNrTel()
    <<" | Clienti: " <<a.getNrClienti()
    <<" | Locuri libere: " <<a.locuriLibere()
    <<" | " <<a.getMaxClienti();

    return out;
}

bool operator<(const Antrenor& a1,const Antrenor& a2)
{
    if(a1.getNrClienti() !=a2.getNrClienti())
        return a1.getNrClienti() < a2.getNrClienti();

    return a1.getIdAntrenor()<a2.getIdAntrenor();
}

void Antrenor::afiseazaClienti(std::ostream& out) const
{
    out<<"Antrenor: "<<numeAntrenor
    <<"(ID "<< idAntrenor<<") - Clienti: ";

    if (nrClientiCurenti == 0)
    {
        out<<"niciun client.\n";
        return;
    }

    for (int i=0;i < nrClientiCurenti;i++)
    {
        out<<clientiId[i];
        if (i+1<nrClientiCurenti)out<<", ";
    }
    out<<"\n";
}

bool Antrenor::checkIn() const
{
    if (nrClientiCurenti<=0)
    {
        std::cout<<"Nu aveti niciun client alocat. Nu puteti face check-in ca antrenor.\nTreceti pe contul de client.\n";
        return false;
    }
    std::cout<<"Check-in antrenor reusit! Spor la antrenament"<<numeAntrenor;
    return true;
}