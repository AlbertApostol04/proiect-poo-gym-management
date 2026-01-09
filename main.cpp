#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <memory>

#include "AbonamentCuAntrenor.h"
#include "AbonamentCuIntrari.h"
#include "AbonamentPerioada.h"
#include "Antrenor.h"
#include "Client.h"
#include "Cutie.h"
#include "PlataCash.h"
#include "PlataCard.h"
#include "FabricaPlati.h"

int main()
{

    int opt=-1,opt2=-1,opt3=-1,nr=-1;


    std::vector<Client>clienti;
    std::vector<std::shared_ptr<Abonament>> abonamente;
    std::vector<std::unique_ptr<Plata>> plati;
    std::map<int,Antrenor>antrenori;


    Cutie<int>clientSelectatId;
    clientSelectatId.setVal(-1);

    Cutie<std::string>clientSelectatNume;
    clientSelectatNume.setVal("");

    Cutie<int>antrenorSelectat;
    antrenorSelectat.setVal(-1);

    FabricaPlati fabricaPlati;

    auto proceseazaPlata= [&](double sumaDePlata)->bool
    {
        try
        {
            auto p= fabricaPlati.creeaza(sumaDePlata);
            if (auto* pcash= dynamic_cast<PlataCash*>(p.get()))
            {
                double baniPrimiti=0.0;
                std::cout<<"Introdu suma primita cash:";
                std::cin>>baniPrimiti;
                pcash->setBaniPrimiti(baniPrimiti);
            }
            p->proceseaza();
            std::cout<<"Plata procesata pentru suma: "<< p->getSuma()<<"\n";

            plati.push_back(std::move(p));
            return true;
         }
        catch (const std::exception& e)
        {
            std::cout<<"Plata esuata: "<<e.what()<<"\n";
            return false;
        }
    };

    Antrenor Alex("Dumitru Alexandru","0733563200");
    Antrenor Adelina("Negraru Adelina Andreea ","072805781");
    Antrenor Mihai("Popescu Mihail","0727863631");
    Antrenor Vlad("Vlad Gavril Gabriel","0767522491");

    antrenori[Alex.getIdAntrenor()] = Alex;
    antrenori[Adelina.getIdAntrenor()] = Adelina;
    antrenori[Mihai.getIdAntrenor()] = Mihai;
    antrenori[Vlad.getIdAntrenor()] = Vlad;


    while (true)
    {
        std::cout<<"Introduceti 1 pentru a intra in meniul clienti\n";
        std::cout<<"Introduceti 2 pentru a intra in meniul antrenori\n";
        std::cout<<"Introduceti 0 pentru a inchide aplicatia\n";

        if (!(std::cin>>opt))
            return 0;
        if (opt == 0)
            break;

        if (opt==1)
        {
            opt2=-1;
            while (opt2!=0)
            {   std::cout<<"\n*Meniu Clienti*\n";
                std::cout<<"\nIntroduceti 1 pentru a adauga client"<<std::endl;
                std::cout<<"Introduceti 2 pentru a afisa clientii"<<std::endl;
                std::cout<<"Introduceti 3 pentru a cauta un client dupa nume"<<std::endl;
                std::cout<<"Introduceti 4 pentru a atasa un abonament unui client"<<std::endl;
                std::cout<<"Introduceti 5 pentru a valida checkin-ul clientului"<<std::endl;
                std::cout<<"Introduceti 0 pentru a parasi meniul Clienti"<<std::endl;

                if (!(std::cin>>opt2))
                    return 0;

                if (opt2==1)
                {   std::string nume,email,nrtel;
                    std::cout<<"Introduceti numele: ";
                    std::getline(std::cin>> std::ws, nume);
                    std::cout<<"Introduceti adresa de email: ";
                    std::getline(std::cin,email);
                    std::cout<<"Introduceti numarul de telefon: ";
                    std::getline(std::cin,nrtel);

                    Client c(nume,email,nrtel);
                    clienti.push_back(std::move(c));
                    std::cout<<"Client adaugat cu succes! ID: "<<clienti.back().getIdClient()<<"\n";
                }
                else if (opt2==2)
                {

                    for(size_t i=0; i < clienti.size(); i++)
                    {
                        std::cout<<clienti[i]<<"\n";
                    }
                    if (clienti.size()==0)
                        std::cout<<"Nu exista clienti";

                }
                else if (opt2==3)
                {
                    std::string numeCautat;
                    std::cout<<"Introduceti(exact) numele clientului: ";
                    std::getline(std::cin>>std::ws,numeCautat);

                    auto it= std::find_if(clienti.begin(), clienti.end(),[&numeCautat](const Client& c) {
                               return c.getNume()==numeCautat;
                           });

                    if (it != clienti.end())
                    {
                        std::cout<<"Client gasit: "<<*it<<"\n";
                        clientSelectatId.setVal(it->getIdClient());
                        clientSelectatNume.setVal(it->getNume());
                        std::cout<<"Selectat: "<<clientSelectatNume.getVal()<<" (ID "<<clientSelectatId.getVal()<<")\n";
                    }
                    else std::cout << "Clientul cautat nu exista.\n";


                }
                else if (opt2==4 )
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
                            std::cout<<"Introduceti numarul 3 pentru abonament cu antrenamente cu antrenor privat.\n";

                            std::cin>>nr;

                            if (nr == 1)
                            {
                                std::cout<<"Sunteti student?\n Introduceti 1 daca sunteti student(a).\n";
                                int verif;
                                bool stud=false;
                                std::cin>>verif;
                                if (verif==1)
                                    stud=true;

                                auto a = std::make_shared<AbonamentCuIntrari>(stud);
                                if (proceseazaPlata(a->getPret())) {
                                    abonamente.push_back(a);
                                    it->setAbonament(a.get());
                                    std::cout<<"Tip: "<<a->getTipAb()<<" | Zile ramase: "<<a->getZileRamase()<<"\n";
                                    }


                            }
                            else if (nr == 2 )
                            {
                                std::cout<<"Pentru abonamentul cu intrari nelimitat avem urmatoarel variante:\nAbonament de 1 zile.\n Abonament de 7 zile. \n Abonament de 14 zile.\n Abonament de 28 zile.\n Introduceti perioada dorita:\n";
                                int zile;
                                std::cin>>zile;
                                std::cout<<"Sunteti student?\n Introduceti 1 daca sunteti student(a).\n";
                                int verif;
                                std::cin>>verif;
                                bool stud=false;
                                if (verif==1)
                                    stud=true;

                                AbonamentPerioada::setTermeniAb("Termeni: acces nelimitat in perioada abonamentului. Maxim 1 check-in pe zi.");

                                try {
                                    auto a = std::make_shared<AbonamentPerioada>(zile, stud);

                                    if (proceseazaPlata(a->getPret())) {
                                        abonamente.push_back(a);
                                        it->setAbonament(a.get());
                                        std::cout<<"Tip: "<<a->getTipAb()<<" | Zile ramase: "<<a->getZileRamase()<<"\n";
                                    }
                                    } catch (const std::exception& e) {
                                    std::cout << "Eroare abonament: " << e.what() << std::endl;
                                }
                            }
                            else if (nr ==3)
                            {
                                try
                                {

                                    std::cout<<"Introduceti numarul de sesiuni dorite:\n";
                                    int zile;
                                    std::cin>>zile;
                                    if (zile <= 0)zile=8;

                                    std::cout<<"Sunteti student?\n Introduceti 1 daca sunteti student(a).\n";
                                    int verif;
                                    bool stud=false;
                                    std::cin>>verif;
                                    if (verif==1)
                                        stud=true;

                                    auto it1= std::min_element(antrenori.begin(), antrenori.end(),
                                        [](const auto& p1, const auto& p2)
                                        {
                                            const Antrenor& t1=p1.second;
                                            const Antrenor& t2=p2.second;

                                            const bool verif1 =t1.disponibil();
                                            const bool verif2 = t2.disponibil();

                                            if(verif1!=verif2) return verif1;

                                            if (verif1)
                                            {
                                               if (t1.getNrClienti()!= t2.getNrClienti())
                                                   return t1.getNrClienti()<t2.getNrClienti();
                                            }

                                            return p1.first < p2.first;
                                        });

                                    if (it1==antrenori.end() || !it1->second.disponibil())
                                    {
                                        std::cout << "Nu exista antrenori disponibili in acest moment\n";
                                    }
                                    else
                                    {
                                        auto a = std::make_shared<AbonamentCuAntrenor>(zile, stud);

                                        auto* abAntrenor = dynamic_cast<AbonamentCuAntrenor*>(a.get());
                                        if (!abAntrenor) {
                                            throw std::runtime_error("Eroare interna: abonamentul ales nu include antrenori.");
                                        }

                                        std::string numeAntrenor = it1->second.getNume();
                                        abAntrenor->setNumeAntrenor(numeAntrenor);

                                        if (proceseazaPlata(a->getPret())) {
                                            it1->second.alocaClient(it->getIdClient());
                                            antrenorSelectat.setVal(it1->first);

                                            abonamente.push_back(a);
                                            it->setAbonament(a.get());
                                            std::cout<<"Tip: "<<a->getTipAb()<<" | Zile ramase: "<<a->getZileRamase()<<"\n";

                                            std::cout << "Antrenor alocat: " << it1->second.getNume() << std::endl;
                                        }
                                    }
                                }
                                catch (const std::exception& e)
                                {
                                    std::cout<<"Eroare"<<e.what()<<std::endl;
                                }
                            }
                            else std::cout<<"Optiune invalida";
                        }
                        else std::cout<<"Clientul are deja abonament";
                    }
                    else std::cout<<"Clientul cautat nu exista"<< std::endl;
                }
                else if (opt2 == 5 )
                {
                    int idCautat;
                    std::cout<<"Introduceti ID-ul: ";
                    std::cin>>idCautat;

                    auto it=std::find_if(clienti.begin(),clienti.end(),[idCautat](const Client& c)
                    {
                        return c.getIdClient()==idCautat;
                    });

                    if (it == clienti.end())
                        std::cout<<"Client inexistent\n";
                    else if (!it->areAbonament())
                        std::cout<<"Clientul nu are abonament\n";
                    else
                    {   const auto*abT=dynamic_cast<const AbonamentCuAntrenor*>(it->getAbonament());
                        if (abT != nullptr)
                        {
                            std::cout << "Abonament cu antrenor: " << abT->getNumeAntrenor() << "\n";
                        }
                        it->getAbonament()->checkIn();
                    }
                }
            }
        }

        else if (opt == 2)
        {
            opt3=-1;
            while (opt3!=0)
            {
                std::cout<<"\n*Meniul Antrenori*\n";
                std::cout<<"\nIntroduceti 1 pentru a afisa antrenori"<<std::endl;
                std::cout<<"Introduceti 2 pentru a afisa antrenorii si clientii acestora"<<std::endl;
                std::cout<<"Introduceti 3 pentru verifica checkin-ul antrenorului"<<std::endl;

                std::cout<<"Introduceti 0 pentru a parasi meniul Antrenori"<<std::endl;

                if (!(std::cin>>opt3))
                    return 0;

                if (opt3 == 1)
                {

                    if (antrenori.empty())
                    {
                        std::cout<<"Nu exista antrenori.\n";
                    }
                    else
                    {
                        std::map<int,Antrenor>::iterator itMap;

                        for (itMap=antrenori.begin(); itMap != antrenori.end(); ++itMap)
                        {
                            std::cout<<itMap->second<<"\n";
                            std::cout<<"Locuri libere: "<<itMap->second.locuriLibere()<<"\n";
                        }
                    }
                }
                else if (opt3 == 2)
                {
                    if (antrenori.empty())
                    {
                        std::cout << "Nu exista antrenori.\n";
                    }
                    else
                    {
                        for (auto itMap = antrenori.begin(); itMap != antrenori.end(); ++itMap)
                        {
                            itMap->second.afiseazaClienti(std::cout);
                        }
                    }
                }
                else if (opt3 == 3)
                {
                    int idAntrenor;
                    std::cout<<"Introduceti ID antrenor: ";
                    std::cin>>idAntrenor;

                    std::map<int,Antrenor>::iterator itAntrenor= antrenori.find(idAntrenor);

                    if (itAntrenor==antrenori.end())
                    {
                        std::cout<<"Antrenor inexistent.\n";
                    }
                    else
                    {
                        itAntrenor->second.checkIn();
                    }
                }
            }
        }
        else std::cout<<"Aceasta optiune nu exista";
    }

    
    return 0;
}
