#include "InfantryFactory.h"

InfantryFactory::InfantryFactory(Soldiers *soldiers) : SoldierFactory(soldiers) {}

Soldiers *InfantryFactory::createUnit() {
    return soldiers->clonis();
}

int InfantryFactory::calculateTotalHealthPerUnit() {

    return soldiers->getHealth() * soldiers->getAmt();
}

int InfantryFactory::calculateTotalDamagePerUnit() {
    return 0;
}

int InfantryFactory::calculateTotalDefencePerUnit() {
    return 0;
}

