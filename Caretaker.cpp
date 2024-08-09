#include "Caretaker.h"


Caretaker::Caretaker() {
    storage = new vector<>;
}

Memento *Caretaker::getMemento(int index) {
    if (storage->size() == 0) {
        return null;
    }

    for (int i = 0; i < storage->size(); i++) {
        if (storage[i] != null) {
            return storage[i];
        }
    }

    return null;
}

int Caretaker::getMementoIndex(Memento *memento) {
    if (storage->size() == 0) {
        return -1;
    }

    for (int i = 0; i < storage->size(); i++) {
        if (storage[i] != null && storage[i] == memento) {
            return i;
            return i;
        }
    }

    return -1;
}

void Caretaker::setMemento(Memento* memento, int value1, int value2, int value3, int value4, string value5) {
    int changeDex = getMementoIndex(memento);

    storage[changeDex].healthPerSolider = value1;
    storage[changeDex].damagePerSoldier = value2;
    storage[changeDex].defencePerSoldier = value3;
    storage[changeDex].amountOfSoldiersPerUnit = value4;
    storage[changeDex].unitName = value5;
}