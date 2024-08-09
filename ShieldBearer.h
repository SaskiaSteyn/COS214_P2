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
        void execute();
        void retreat();
        void rest();

    public:
        ShieldBearer(int health, int damage, int defence, int amt, string name);

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

#endif //PRAC2_SHIELDBEARER_H
