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
        Soldiers * clonis();
        void engage();
        void disengage();


        int getHealth();
        int getDamage();
        int getDefence();
        int getAmt();

//    friend class InfantryFactory;
};

#endif //PRAC2_INFANTRY_H
