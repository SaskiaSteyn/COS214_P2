#ifndef PRAC2_MEMENTO_H
#define PRAC2_MEMENTO_H

#include <iostream>

using namespace std;

class Memento {
    private:
        int healthPerSoldier;
        int damagePerSoldier;
        int defencePerSoldier;
        int amountOfSoldiersPerUnit;
        string unitName;

        Memento(int value1, int value2, int value3, int value4, int value5);
};


#endif //PRAC2_MEMENTO_H
