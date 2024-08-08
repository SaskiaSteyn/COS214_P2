#ifndef PRAC2_SHIELDBEARER_H
#define PRAC2_SHIELDBEARER_H

#include "Soldiers.h"
#include "ShieldBearerFactory.h"

#include <iostream>

using namespace std;

class ShieldBearer : private Soldiers{
    private:
        int healthPerSoldier;
        int damagePerSoldier;
        int defencePerSoldier;
        int amountOfSoldiersPerUnit;
        string unitName;

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


        void engage();
        void disengage();

        Memento * militusMemento();
        void vivificaMemento(Memento * mem);
};

#endif //PRAC2_SHIELDBEARER_H
