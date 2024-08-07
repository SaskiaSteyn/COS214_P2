#include "ShieldBearer.h"

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

