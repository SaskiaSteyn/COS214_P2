#include "Soldiers.h"

Soldiers::Soldiers(int health, int damage, int totalDamage, int defence, int amt, string name) {
    this->healthPerSoldier = health;
    this->damagePerSoldier = damage;
    this->totalDamageCaused = totalDamage;
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

Memento *Soldiers::militusMemento() {
    return nullptr;
}

void Soldiers::vivificaMemento(Memento *mem) {
    return;
}

Soldiers::~Soldiers() {

}

string Soldiers::getType() {
    return this->type;
}




