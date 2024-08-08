
#include "Boatman.h"

Boatman::Boatman(int health, int damage, int defence, int amt, string name) : Soldiers(health, damage, defence, amt, name) {}

Soldiers *Boatman::clonis() {
    return nullptr;
}

void Boatman::prepare() {

}

void Boatman::execute() {

}

void Boatman::retreat() {

}

void Boatman::rest() {

}

void Boatman::engage() {
    Soldiers::engage();
}

void Boatman::disengage() {
    Soldiers::disengage();
}

int Boatman::getHealth() {
    return healthPerSoldier;
}

int Boatman::getAmt() {
    return amountOfSoldiersPerUnit;
}

int Boatman::getDamage() {
    return damagePerSoldier;
}

int Boatman::getDefence() {
    return defencePerSoldier;
}


