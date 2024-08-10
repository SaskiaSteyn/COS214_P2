#ifndef PRAC2_MEMENTO_H
#define PRAC2_MEMENTO_H

#include <iostream>
//#include "Caretaker.h"

using namespace std;

class Memento {
protected:
    int healthPerSoldier;
    int damagePerSoldier;
    int totalDamageCaused;
    int defencePerSoldier;
    int amountOfSoldiersPerUnit;
    string unitName;

public:
    Memento(int healthPerSoldier, int damagePerSoldier, int totalDamage, int defencePerSoldier, int amountOfSoldiersPerUnit, string unitName);

    int getHealth();
    int getDamage();
    int getTotalDamage();
    int getDefence();
    int getAmt();
    string getName();

    void setHealth(int hp);
    void setDamage(int dmg);
    void setTotalDamage(int tDamage);
    void setDefence(int def);
    void setAmt(int amt);
    void setName(string name);
};


#endif //PRAC2_MEMENTO_H