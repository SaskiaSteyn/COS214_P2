#ifndef PRAC2_MEMENTO_H
#define PRAC2_MEMENTO_H

#include <iostream>
#include "Caretaker.h"

using namespace std;

class Memento {
    private:
        int healthPerSoldier;
        int damagePerSoldier;
        int defencePerSoldier;
        int amountOfSoldiersPerUnit;
        string unitName;

        Memento(int value1, int value2, int value3, int value4, string value5);

        friend class Caretaker
};


#endif //PRAC2_MEMENTO_H
