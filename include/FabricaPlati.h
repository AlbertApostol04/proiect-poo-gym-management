#pragma once
#include "Plata.h"
#include<memory>

class FabricaPlati
{

public:

    std::unique_ptr<Plata> creeaza(double sumaDePlata) const;
};