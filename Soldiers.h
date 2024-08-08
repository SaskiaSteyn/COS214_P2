#ifndef PRAC2_SOLDIERS_H
#define PRAC2_SOLDIERS_H

#include "Memento.h"
#include <iostream>
using namespace std;


class Soldiers {
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

        Soldiers(int health, int damage, int defence, int amt, string name);

        virtual Soldiers * clonis() = 0;
        virtual int getHealth() = 0;
        virtual int getDamage() = 0;
        virtual int getDefence() = 0;
        virtual int getAmt() = 0;


        virtual void engage();
        void disengage();

        Memento * militusMemento();
        void vivificaMemento(Memento * mem);
};

#endif //PRAC2_SOLDIERS_H
