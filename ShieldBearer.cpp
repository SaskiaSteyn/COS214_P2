#include "ShieldBearer.h"

ShieldBearer::ShieldBearer(int health, int damage, int defence, int amt, string name) : Soldiers(health, damage, defence, amt, name) {}

Soldiers *ShieldBearer::clonis() {
    return nullptr;
}

void ShieldBearer::engage() {
    Soldiers::engage();
}

void ShieldBearer::disengage() {
    Soldiers::disengage();
}

void ShieldBearer::prepare() {

}

void ShieldBearer::execute() {

}

void ShieldBearer::retreat() {

}

void ShieldBearer::rest() {

}

int ShieldBearer::getHealth() {
    return healthPerSoldier;
}

int ShieldBearer::getAmt() {
    return amountOfSoldiersPerUnit;
}

int ShieldBearer::getDamage() {
    return damagePerSoldier;
}

int ShieldBearer::getDefence() {
    return defencePerSoldier;
}

