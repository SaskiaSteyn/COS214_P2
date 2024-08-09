#include "Memento.h"

Memento::Memento(int value1, int value2, int value3, int value4, string value5) {
    this->healthPerSoldier = value1;
    this->damagePerSoldier = value2;
    this->defencePerSoldier = value3;
    this->amountOfSoldiersPerUnit = value4;
    this->unitName = value5;
}
