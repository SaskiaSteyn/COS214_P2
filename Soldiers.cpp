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
    return new Memento(this->healthPerSoldier, this->damagePerSoldier, this->totalDamageCaused, this->defencePerSoldier, this->amountOfSoldiersPerUnit, this->unitName);
}

void Soldiers::vivificaMemento(Memento *mem) {
    this->healthPerSoldier = mem->getHealth();
    this->damagePerSoldier = mem->getDamage();
    this->totalDamageCaused = mem->getTotalDamage();
    this->defencePerSoldier = mem->getDefence();
    this->amountOfSoldiersPerUnit = mem->getAmt();
    this->unitName = mem->getName();
}

Soldiers::~Soldiers() {

}

string Soldiers::getType() {
    return this->type;
}




