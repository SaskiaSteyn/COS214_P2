#include "Memento.h"

Memento::Memento(int value1, int value2, int value3, int value4, string value5) {
    this->healthPerSoldier = value1;
    this->damagePerSoldier = value2;
    this->defencePerSoldier = value3;
    this->amountOfSoldiersPerUnit = value4;
    this->unitName = value5;
}

int Memento::getHealth() {
    return healthPerSoldier;
}

int Memento::getDamage() {
    return damagePerSoldier;
}

int Memento::getDefence() {
    return defencePerSoldier;
}

int Memento::getAmt() {
    return amountOfSoldiersPerUnit;
}

string Memento::getName() {
    return unitName;
}

void Memento::setHealth(int hp) {
    this->healthPerSoldier = hp;
}

void Memento::setDamage(int dmg) {
    this->damagePerSoldier = dmg;
}

void Memento::setDefence(int def) {
    this->defencePerSoldier = def;
}

void Memento::setAmt(int amt) {
    this->amountOfSoldiersPerUnit = amt;
}

void Memento::setName(string name) {
    this->unitName = name;
}