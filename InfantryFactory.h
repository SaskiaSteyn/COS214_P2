#ifndef PRAC2_INFANTRYFACTORY_H
#define PRAC2_INFANTRYFACTORY_H

#include "SoldierFactory.h"

using namespace std;

class InfantryFactory : private SoldierFactory{
    public:
        Soldiers * createUnit();
        int calculateTotalHealthPerUnit();
        int calculateTotalDamagePerUnit();
        int calculateTotalDefencePerUnit();
};

#endif //PRAC2_INFANTRYFACTORY_H
