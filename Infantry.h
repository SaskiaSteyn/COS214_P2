#ifndef PRAC2_INFANTRY_H
#define PRAC2_INFANTRY_H

#include "Soldiers.h"
#include "InfantryFactory.h"
#include <iostream>

using namespace std;

class Infantry : public Soldiers{
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
        Infantry(int health, int damage, int defence, int amt, string name);

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

#endif //PRAC2_INFANTRY_H
