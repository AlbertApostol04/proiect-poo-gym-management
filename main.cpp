#include <iostream>
#include <vector>
#include<algorithm>

#include "AbonamentCuIntrari.h"
#include "AbonamentPerioada.h"
#include "Client.h"

int main()
{
    int opt=-1,nr=-1;
    std::vector<Client>clienti;
    std::vector<Abonament*>abonamente;



    while (opt!=0)
    {
        std::cout<<"\nIntroduceti 1 pentru a adauga client"<<std::endl;
        std::cout<<"Introduceti 2 pentru a afisa clientii"<<std::endl;
        std::cout<<"Introduceti 3 pentru a cauta un client dupa Id"<<std::endl;
        std::cout<<"Introduceti 0 pentru a inchide aplicatia"<<std::endl;
        std::cout<<"Introduceti 4 pentru a atasa un abonament unui client"<<std::endl;

        std::cin>>opt;
        if (opt==1)
        {   std::string nume,email,nrtel;
            std::getline(std::cin>> std::ws, nume);
            std::getline(std::cin,email);
            std::getline(std::cin,nrtel);
            Client c(nume,email,nrtel);
            clienti.push_back(c);
        }
        else if (opt==2)
        {
            for(int i=0; i < clienti.size(); i++)
            {
                std::cout<<clienti[i]<<"\n";
            }
            if (clienti.size()==0)
                std::cout<<"Nu exista clienti";

        }
        else if (opt==3)
        {
            int idCautat;
            std::cout<<"Introduceti ID-ul: ";
            std::cin>>idCautat;

            auto it=std::find_if(clienti.begin(),clienti.end(),[idCautat](const Client& c)
            {
                return c.getIdClient()==idCautat;
            });

            if (it != clienti.end())
            {
                std::cout<<"Client gasit "<< *it << std::endl;
            }
            else std::cout<<"Clientul cautat nu exista"<< std::endl;
        }
        else if (opt == 4 )
        {
            int idCautat;
            std::cout<<"Introduceti ID-ul: ";
            std::cin>>idCautat;

            auto it=std::find_if(clienti.begin(),clienti.end(),[idCautat](const Client& c)
            {
                return c.getIdClient()==idCautat;
            });

            if (it != clienti.end())
            {
                if (!it->areAbonament())
                {
                    std::cout<<"Introduceti numarul 1 pentru abonament cu 8 intrari.\n";
                    std::cout<<"Introduceti numarul 2 pentru abonament cu intrari nelimitate.\n";

                    std::cin>>nr;

                    if (nr == 1)
                    {
                        std::cout<<"Sunteti student?\n Introduceti 1 daca da sunteti sau 0 daca nu sunteti.\n";
                        int verif;
                        bool stud=false;
                        std::cin>>verif;
                        if (verif==1)
                            stud=true;
                        else if (verif !=0 && verif!=1)
                            std::cout<<"Numarul introdus nu este valabil\n";

                        Abonament* a=new AbonamentCuIntrari(stud);
                        abonamente.push_back(a);
                        it->setAbonament(a);
                    }
                    else if (nr == 2 )
                    {
                        std::cout<<"Pentru abonamentul cu intrari nelimitat avem urmatoarel variante:\nAbonament de 1 zile.\n Abonament de 7 zile. \n Abonament de 14 zile.\n Abonament de 28 zile.\n Introduceti perioada dorita:\n";
                        int zile;
                        std::cin>>zile;

                        std::cout<<"Sunteti student?\n Introduceti 1 daca da sunteti sau 0 daca nu sunteti.\n";
                        int verif;
                        std::cin>>verif;
                        bool stud=false;
                        if (verif==1)
                            stud=true;
                        else if (verif !=0 && verif!=1)
                            std::cout<<"Numarul introdus nu este valabil\n";

                        Abonament* a=new AbonamentPerioada(zile,stud);
                        abonamente.push_back(a);
                        it->setAbonament(a);
                    }
                    else std::cout<<"Optiune invalida";
                }
                else std::cout<<"Clientul are deja abonament";
            }

            else std::cout<<"Clientul cautat nu exista"<< std::endl;

        }
    }
    for (int i=0; i<abonamente.size();i++)
    {
        delete abonamente[i];
    }
}