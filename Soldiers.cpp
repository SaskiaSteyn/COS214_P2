#include "Soldiers.h"

Soldiers::Soldiers(int health, int damage, int defence, int amt, string name) {
    this->healthPerSoldier = health;
    this->damagePerSoldier = damage;
    this->defencePerSoldier = defence;
    this->amountOfSoldiersPerUnit = amt;
    this->unitName = name;
    this->enemy = nullptr;
}

void Soldiers::engage(Soldiers * newEnemy) {

    this->enemy = newEnemy;
    newEnemy->enemy = this;
    prepare();
    enemy->prepare();
    fighting = true;
    newEnemy->fighting = true;
    execute();
    enemy->execute();
    disengage();
    enemy->disengage();

}

void Soldiers::disengage() {

    retreat();
    fighting = false;
    rest();

}

//bool Soldiers::isEngaged() {
//    return fighting;
//}

Memento *Soldiers::militusMemento() {
    return nullptr;
}

void Soldiers::vivificaMemento(Memento *mem) {

}

Soldiers::~Soldiers() {

}

string Soldiers::getType() {
    return this->type;
}




