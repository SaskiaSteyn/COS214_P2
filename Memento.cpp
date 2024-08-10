#include "Memento.h"

Memento::Memento(int healthPerSoldier, int damagePerSoldier, int totalDamage, int defencePerSoldier, int amountOfSoldiersPerUnit, string unitName) {
    this->healthPerSoldier = healthPerSoldier;
    this->damagePerSoldier = damagePerSoldier;
    this->totalDamageCaused = totalDamage;
    this->defencePerSoldier = defencePerSoldier;
    this->amountOfSoldiersPerUnit = amountOfSoldiersPerUnit;
    this->unitName = unitName;
}

int Memento::getHealth() {
    return healthPerSoldier;
}

int Memento::getDamage() {
    return damagePerSoldier;
}

int Memento::getTotalDamage() {
    return this->totalDamageCaused;
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

void Memento::setTotalDamage(int tDamage) {
    this->totalDamageCaused = tDamage;
}


string Memento::printFunc() {
    string output = "";
    string health = to_string(this->getHealth());
    output += this->getName() + "'s health is " + health + "\n";

    return output;
}
