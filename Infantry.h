#ifndef PRAC2_INFANTRY_H
#define PRAC2_INFANTRY_H

#include "Soldiers.h"
#include <iostream>

using namespace std;

class Infantry : private Soldiers{
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


};

#endif //PRAC2_INFANTRY_H
