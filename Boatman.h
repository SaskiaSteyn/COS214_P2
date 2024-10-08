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
    void execute(Soldiers * attacker);
    void retreat();
    bool rest();

public:
    Boatman(int health, int damage, int totalDamage, int defence, int amt, string name);

    Soldiers * clonis();
    int getHealth();
    int getDamage();
    int getTotalDamage();
    int getDefence();
    int getAmt();
    string getName();

    int setAmount(int amount);
    int setHealth(int health);

    int dealDamage(int damageDealt, Soldiers * attacker);
};

#endif //PRAC2_BOATMAN_H
