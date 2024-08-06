#ifndef PRAC2_SHIELDBEARERFACTORY_H
#define PRAC2_SHIELDBEARERFACTORY_H

#include "SoldierFactory.h"

using namespace std;

class ShieldBearerFactory : private SoldierFactory{
    public:
        Soldiers * createUnit();
        int calculateTotalHealthPerUnit();
        int calculateTotalDamagePerUnit();
        int calculateTotalDefencePerUnit();
};

#endif //PRAC2_SHIELDBEARERFACTORY_H
