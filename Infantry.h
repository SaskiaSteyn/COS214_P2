#ifndef PRAC2_INFANTRY_H
#define PRAC2_INFANTRY_H

#include "Soldiers.h"
#include "InfantryFactory.h"

#include "Boatman.h"
#include "ShieldBearer.h"

#include <iostream>
#include <typeinfo>

using namespace std;

class Infantry : public Soldiers{
    private:
        //variables
        bool hasGun;
        bool gunLoaded;

        //Functions
        void prepare();
        void execute(Soldiers * attacker);
        void retreat();
        bool rest();

    public:
        Infantry(int health, int damage, int totalDamage, int defence, int amt, string name);

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

#endif //PRAC2_INFANTRY_H
