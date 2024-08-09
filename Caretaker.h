//
// Created by Joshua Cilliers on 2024/08/06.
//

#ifndef PRAC2_CARETAKER_H
#define PRAC2_CARETAKER_H

#include <iostream>
#include <vector>
#include "Memento.h"

using namespace std;

class Caretaker {
    private:
        vector<Memento> *storage;
    public:
        Caretaker();
        Memento* getMemento(int index);
        int getMementoIndex(Memento* memento);
        void setMemento(Memento* memento, int value1, int value2, int value3, int value4, string value5);
};


#endif //PRAC2_CARETAKER_H
