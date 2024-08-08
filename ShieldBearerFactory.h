#ifndef PRAC2_SHIELDBEARERFACTORY_H
#define PRAC2_SHIELDBEARERFACTORY_H

#include <iostream>

#include "SoldierFactory.h"
#include "ShieldBearer.h"

using namespace std;

class ShieldBearerFactory : private SoldierFactory{
    public:
        ShieldBearerFactory(Soldiers* soldiers);
        Soldiers * createUnit();
        int calculateTotalHealthPerUnit();
        int calculateTotalDamagePerUnit();
        int calculateTotalDefencePerUnit();
};

#endif //PRAC2_SHIELDBEARERFACTORY_H
