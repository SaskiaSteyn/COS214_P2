#include "Caretaker.h"


Caretaker::Caretaker() {

}

Memento *Caretaker::getMemento(int index) {
    if (storage.empty()) {
        return nullptr;
    }

    int count = 0;
    for (auto item: storage) {
        if (count == index && item != nullptr) {
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

    for (int i = 0; i < storage.size(); i++) {
        if (storage[i] != nullptr && storage[i] == memento) {
            return i;
        }
    }

    return -1;
}

void Caretaker::addMemento(int healthPerSoldier, int damagePerSoldier, int totalDamage, int defencePerSoldier, int amountOfSoldiersPerUnit, string unitName) {
    Memento *mento = new Memento(healthPerSoldier, damagePerSoldier, totalDamage, defencePerSoldier, amountOfSoldiersPerUnit, unitName);

    storage.push_back(mento);
}

void Caretaker::addMemento(Memento *memento) {
    storage.push_back(memento);
}