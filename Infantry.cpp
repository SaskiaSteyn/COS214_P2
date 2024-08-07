#include "Infantry.h"

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
