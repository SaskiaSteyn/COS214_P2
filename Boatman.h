#ifndef PRAC2_BOATMAN_H
#define PRAC2_BOATMAN_H

#include "Soldiers.h"
#include "BoatmanFactory.h"

#include <iostream>
#include <typeinfo>

#include "Infantry.h"
#include "ShieldBearer.h"

using namespace std;

class Boatman : public Soldiers{
private:
    //variables
    bool hasOar;
    bool raisedOar;

    //Functions
    void prepare();
    void execute();
    void retreat();
    void rest();

public:
    Boatman(int health, int damage, int defence, int amt, string name);

    Soldiers * clonis();
    int getHealth();
    int getDamage();
    int getDefence();
    int getAmt();
    string getName();

    int dealDamage(int damageDealt);

    Memento * militusMemento();
    void vivificaMemento(Memento * mem);
};

#endif //PRAC2_BOATMAN_H
