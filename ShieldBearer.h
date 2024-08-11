#ifndef PRAC2_SHIELDBEARER_H
#define PRAC2_SHIELDBEARER_H

#include "Soldiers.h"
#include "ShieldBearerFactory.h"

#include "Infantry.h"
#include "Boatman.h"

#include <iostream>
#include <typeinfo>

using namespace std;

class ShieldBearer : public Soldiers{
    private:
    //variables
        bool hasShield;
        bool shieldRaised;

    //Functions
        void prepare();
        void execute(Soldiers * attacker);
        void retreat();
        bool rest();

    public:
        ShieldBearer(int health, int damage, int totalDamage, int defence, int amt, string name);

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

#endif //PRAC2_SHIELDBEARER_H
