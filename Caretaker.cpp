#include "Caretaker.h"


Caretaker::Caretaker() {

}

Memento *Caretaker::getMemento(int index) {
    if (storage.empty()) {
        return nullptr;
    }

    int count = 0;
    for (auto item: storage) {
        if (storage.empty()) {
            return item;
        }

        count++;
    }

    return nullptr;
}

int Caretaker::getMementoIndex(Memento *memento) {
    if (storage.empty()) {
        return -1;
    }

    int count = 0;
    for (auto item: storage) {
        if (storage.empty()) {
            return count;
        }

        count++;
    }

    return -1;
}

void Caretaker::addMemento(int healthPerSoldier, int damagePerSoldier, int totalDamage, int defencePerSoldier, int amountOfSoldiersPerUnit, string unitName) {
    Memento *mento = new Memento(healthPerSoldier, damagePerSoldier, totalDamage, defencePerSoldier, amountOfSoldiersPerUnit, unitName);

    storage.push_back(mento);
}