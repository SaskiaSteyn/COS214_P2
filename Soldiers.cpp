#include "Soldiers.h"

Soldiers::Soldiers(int health, int damage, int defence, int amt, string name) {
    this->healthPerSoldier = health;
    this->damagePerSoldier = damage;
    this->defencePerSoldier = defence;
    this->amountOfSoldiersPerUnit = amt;
    this->unitName = name;
}

void Soldiers::prepare() {

}

void Soldiers::execute() {

}

void Soldiers::retreat() {

}

void Soldiers::rest() {

}

void Soldiers::engage() {

}

void Soldiers::disengage() {

}

Memento *Soldiers::militusMemento() {
    return nullptr;
}

void Soldiers::vivificaMemento(Memento *mem) {

}

