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

void Caretaker::addMemento(int value1, int value2, int value3, int value4, string value5) {
    Memento *mento = new Memento(value1, value2, value3, value4, value5);

    storage.push_back(mento);
}