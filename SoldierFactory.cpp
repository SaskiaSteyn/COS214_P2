#include "SoldierFactory.h"

SoldierFactory::SoldierFactory(Soldiers *soldiers) {
    this->soldiers = soldiers;
}

Soldiers *SoldierFactory::getSoldier() {
    return this->soldiers;
}
