#include "BoatmanFactory.h"

BoatmanFactory::BoatmanFactory(Soldiers *soldiers) : SoldierFactory(soldiers) {}

Soldiers *BoatmanFactory::createUnit() {
    return getSoldier()->clonis();
}

int BoatmanFactory::calculateTotalHealthPerUnit() {
    return getSoldier()->getHealth() * getSoldier()->getAmt();
}

int BoatmanFactory::calculateTotalDamagePerUnit() {
    return getSoldier()->getDamage() * getSoldier()->getAmt();
}

int BoatmanFactory::calculateTotalDefencePerUnit() {
    return getSoldier()->getDefence() * getSoldier()->getAmt();
}