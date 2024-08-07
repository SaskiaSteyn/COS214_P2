#ifndef PRAC2_BOATMANFACTORY_H
#define PRAC2_BOATMANFACTORY_H


#include <iostream>



using namespace std;

class BoatmanFactory : private SoldierFactory{
public:
    Soldiers * createUnit();
    int calculateTotalHealthPerUnit();
    int calculateTotalDamagePerUnit();
    int calculateTotalDefencePerUnit();
};

#endif //PRAC2_BOATMANFACTORY_H
