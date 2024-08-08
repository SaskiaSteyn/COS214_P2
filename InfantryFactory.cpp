#include "InfantryFactory.h"

InfantryFactory::InfantryFactory(Soldiers* soldiers) : SoldierFactory(soldiers) {}

Soldiers *InfantryFactory::createUnit() {
    return getSoldier()->clonis();
}

int InfantryFactory::calculateTotalHealthPerUnit() {
    return getSoldier()->getHealth() * getSoldier()->getAmt();
}

int InfantryFactory::calculateTotalDamagePerUnit() {
    return getSoldier()->getDamage() * getSoldier()->getAmt();
}

int InfantryFactory::calculateTotalDefencePerUnit() {
    return getSoldier()->getDefence() * getSoldier()->getAmt();
}

