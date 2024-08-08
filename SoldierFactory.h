#ifndef PRAC2_SOLDIERFACTORY_H
#define PRAC2_SOLDIERFACTORY_H

#include "Soldiers.h"

class SoldierFactory {
    private:
        Soldiers * soldiers;

    protected:

        SoldierFactory(Soldiers *soldiers);

        virtual Soldiers * createUnit() = 0;
        virtual int calculateTotalHealthPerUnit() = 0;
        virtual int calculateTotalDamagePerUnit() = 0;
        virtual int calculateTotalDefencePerUnit() = 0;

        Soldiers* getSoldier();
};

#endif //PRAC2_SOLDIERFACTORY_H
