#ifndef PRAC2_MEMENTO_H
#define PRAC2_MEMENTO_H

#include <iostream>
//#include "Caretaker.h"

using namespace std;

class Memento {
protected:
    int healthPerSoldier;
    int damagePerSoldier;
    int defencePerSoldier;
    int amountOfSoldiersPerUnit;
    string unitName;

public:
    Memento(int value1, int value2, int value3, int value4, string value5);

    int getHealth();
    int getDamage();
    int getDefence();
    int getAmt();
    string getName();

    void setHealth(int hp);
    void setDamage(int dmg);
    void setDefence(int def);
    void setAmt(int amt);
    void setName(string name);
};


#endif //PRAC2_MEMENTO_H