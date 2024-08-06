#ifndef PRAC2_SOLDIERS_H
#define PRAC2_SOLDIERS_H

#include "Memento.h"
#include <iostream>
using namespace std;


class Soldiers : private Memento{
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
        virtual Soldiers * clonis() = 0;

    virtual void engage();
        void disengage();

        Memento * militusMemento();
        void vivificaMemento(Memento * mem);

};

#endif //PRAC2_SOLDIERS_H
