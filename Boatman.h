#ifndef PRAC2_BOATMAN_H
#define PRAC2_BOATMAN_H

#include "Soldiers.h"
#include "BoatmanFactory.h"

using namespace std;

class Boatman : private Soldiers{
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

        friend class BoatmanFactory;
};

#endif //PRAC2_BOATMAN_H
