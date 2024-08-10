#ifndef PRAC2_CARETAKER_H
#define PRAC2_CARETAKER_H

#include <iostream>
#include <vector>
#include "Memento.h"

using namespace std;

class Caretaker {
private:
    vector<Memento*> storage;
public:
    Caretaker();
    Memento* getMemento(int index);
    int getMementoIndex(Memento* memento);
    void addMemento(int healthPerSoldier, int damagePerSoldier, int totalDamage, int defencePerSoldier, int amountOfSoldiersPerUnit, string unitName);
    void addMemento(Memento *memento);
//        friend class Memento;
};


#endif //PRAC2_CARETAKER_H