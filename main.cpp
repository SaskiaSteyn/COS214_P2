#include <iostream>

#include "Infantry.h"
#include "Boatman.h"
#include "ShieldBearer.h"

#include "InfantryFactory.h"
#include "BoatmanFactory.h"
#include "ShieldBearerFactory.h"

using namespace std;

void testSoldiers() {
    Infantry infantrySoldier(200, 20, 12, 50, "Footmen");
    Boatman boatmanSoldier(200, 20, 12, 50, "Sailor");
    ShieldBearer shieldBearerSoldier(200, 20, 12, 50, "Shieldmaiden");
}

void testFactories() {

}

int main() {

    return 0;
};
