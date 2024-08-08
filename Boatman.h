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
        Boatman(int health, int damage, int defence, int amt, string name);

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

#endif //PRAC2_BOATMAN_H
