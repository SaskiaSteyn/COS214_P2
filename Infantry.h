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
        void execute();
        void retreat();
        void rest();

    public:
        Infantry(int health, int damage, int defence, int amt, string name);

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

#endif //PRAC2_INFANTRY_H
