#include "ShieldBearerFactory.h"

ShieldBearerFactory::ShieldBearerFactory(Soldiers *soldiers) : SoldierFactory(soldiers){}

Soldiers *ShieldBearerFactory::createUnit() {
    return getSoldier()->clonis();
}

int ShieldBearerFactory::calculateTotalHealthPerUnit() {
    return getSoldier()->getHealth() * getSoldier()->getAmt();
}

int ShieldBearerFactory::calculateTotalDamagePerUnit() {
    return getSoldier()->getDamage() * getSoldier()->getAmt();
}

int ShieldBearerFactory::calculateTotalDefencePerUnit() {
    return getSoldier()->getDefence() * getSoldier()->getAmt();
}



