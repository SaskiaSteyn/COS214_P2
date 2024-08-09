#ifndef PRAC2_SOLDIERS_H
#define PRAC2_SOLDIERS_H

#include "Memento.h"
#include <iostream>
#include <typeinfo>

using namespace std;


class Soldiers {
    public:
        Soldiers(int health, int damage, int totalDamage, int defence, int amt, string name);
        ~Soldiers();

        virtual Soldiers * clonis() = 0;
        virtual int getHealth() = 0;
        virtual int getDamage() = 0;
        virtual int getTotalDamage() = 0;
        virtual int getDefence() = 0;
        virtual int getAmt() = 0;
        virtual string getName() = 0;

        virtual int dealDamage(int damageDealt) = 0;

        virtual void engage(Soldiers * newEnemy);
        void disengage();

        virtual string getType();

        Memento * militusMemento();
        void vivificaMemento(Memento * mem);

    protected:
        Soldiers * enemy;
        bool fighting;

        int healthPerSoldier;
        int damagePerSoldier;
        int totalDamageCaused;
        int defencePerSoldier;
        int amountOfSoldiersPerUnit;
        string unitName;
        string type;

        virtual void prepare() = 0;
        virtual void execute() = 0;
        virtual void retreat() = 0;
        virtual void rest() = 0;
};

#endif //PRAC2_SOLDIERS_H
