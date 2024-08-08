#include "Infantry.h"

Infantry::Infantry(int health, int damage, int defence, int amt, string name) : Soldiers(health, damage, defence, amt, name) {}

Soldiers *Infantry::clonis() {
    return nullptr;
}

void Infantry::prepare() {

}

void Infantry::execute() {

}

void Infantry::retreat() {

}

void Infantry::rest() {

}

int Infantry::getHealth() {
    return healthPerSoldier;
}

int Infantry::getAmt() {
    return amountOfSoldiersPerUnit;
}

void Infantry::engage() {
    Soldiers::engage();
}

void Infantry::disengage() {
    Soldiers::disengage();
}

int Infantry::getDamage() {
    return damagePerSoldier;
}

int Infantry::getDefence() {
    return defencePerSoldier;
}
