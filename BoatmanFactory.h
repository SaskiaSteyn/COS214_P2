#ifndef PRAC2_BOATMANFACTORY_H
#define PRAC2_BOATMANFACTORY_H


#include <iostream>

#include "SoldierFactory.h"
#include "Boatman.h"

using namespace std;

class BoatmanFactory : public SoldierFactory {
    public:
        BoatmanFactory(Soldiers* soldiers);
        Soldiers * createUnit();
        int calculateTotalHealthPerUnit();
        int calculateTotalDamagePerUnit();
        int calculateTotalDefencePerUnit();
};

#endif //PRAC2_BOATMANFACTORY_H
