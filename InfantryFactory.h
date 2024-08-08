#ifndef PRAC2_INFANTRYFACTORY_H
#define PRAC2_INFANTRYFACTORY_H

#include <iostream>

#include "SoldierFactory.h"
#include "Infantry.h"

using namespace std;

class InfantryFactory : public SoldierFactory {
    public:
        InfantryFactory(Soldiers* soldiers);
        Soldiers * createUnit();
        int calculateTotalHealthPerUnit();
        int calculateTotalDamagePerUnit();
        int calculateTotalDefencePerUnit();
};

#endif //PRAC2_INFANTRYFACTORY_H
