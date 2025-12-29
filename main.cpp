#include <iostream>
#include <vector>
#include "Client.h"

int main()
{
    std::vector<Client>clienti;
    Client client1("Nume1","email1","nrtel1"),client2("Nume2","email2","nrtel2");

    clienti.push_back(client1);
    clienti.push_back(client2);

    for (int i=0; i <2; i++)
    {
        std::cout<<clienti[i]<<" ";
    }
}