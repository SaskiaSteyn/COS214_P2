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

    cout << "You have these soldiers: " << infantrySoldier.getName() << " | " << boatmanSoldier.getName() << " | " << shieldBearerSoldier.getName() << endl << endl;

    Soldiers * clonedSoldier = infantrySoldier.clonis();
    Soldiers * clonedBoatman = boatmanSoldier.clonis();
    Soldiers * clonedShield = shieldBearerSoldier.clonis();

    cout << "This is a copy of the soldier." << endl;
    cout << "===================================================" << endl;
    cout << "Here are the stats of the og soldier: " << endl;
    cout << "Name: " << infantrySoldier.getName() << endl;
    cout << "Health " << infantrySoldier.getHealth() << endl;
    cout << "Damage: " << infantrySoldier.getDamage() << endl;
    cout << "Defence: " << infantrySoldier.getDefence() << endl;
    cout << "Amount: " << infantrySoldier.getAmt() << endl << endl;

    cout << "===================================================" << endl;
    cout << "Here are the stats of the copied soldier: " << endl;
    cout << "Name: " << clonedSoldier->getName() << endl;
    cout << "Health " << clonedSoldier->getHealth() << endl;
    cout << "Damage: " << clonedSoldier->getDamage() << endl;
    cout << "Defence: " << clonedSoldier->getDefence() << endl;
    cout << "Amount: " << clonedSoldier->getAmt() << endl << endl;

    cout << "===================================================" << endl;
    cout << "The battle starts" << endl;


    cout << "===================================================" << endl;
    cout << "Here are the stats of the Infantry soldiers before the fight: " << endl;
    cout << "Name: " << infantrySoldier.getName() << endl;
    cout << "Health " << infantrySoldier.getHealth() << endl;
    cout << "Damage: " << infantrySoldier.getDamage() << endl;
    cout << "Defence: " << infantrySoldier.getDefence() << endl;
    cout << "Amount: " << infantrySoldier.getAmt() << endl << endl;


    cout << "====================Infantry vs Boatmen====================" << endl;
    infantrySoldier.engage(clonedBoatman);

    cout << "====================Infantry vs Infantry====================" << endl;
    infantrySoldier.engage(clonedSoldier);

    cout << "====================Infantry vs Shields====================" << endl;
    infantrySoldier.engage(clonedShield);

    cout << endl << endl << "===================================================" << endl;
    cout << "Here are the stats of the after the fight Infantry: " << endl;
    cout << "Name: " << infantrySoldier.getName() << endl;
    cout << "Health " << infantrySoldier.getHealth() << endl;
    cout << "Damage: " << infantrySoldier.getDamage() << endl;
    cout << "Defence: " << infantrySoldier.getDefence() << endl;
    cout << "Amount: " << infantrySoldier.getAmt() << endl << endl;



    cout << "===================================================" << endl;
    cout << "Here are the stats of the shield bearers before the fight: " << endl;
    cout << "Name: " << shieldBearerSoldier.getName() << endl;
    cout << "Health " << shieldBearerSoldier.getHealth() << endl;
    cout << "Damage: " << shieldBearerSoldier.getDamage() << endl;
    cout << "Defence: " << shieldBearerSoldier.getDefence() << endl;
    cout << "Amount: " << shieldBearerSoldier.getAmt() << endl << endl;

    cout << "====================Shields vs Infantry====================" << endl;
    shieldBearerSoldier.engage(clonedSoldier);

    cout << "====================Shields vs Boatmen====================" << endl;
    shieldBearerSoldier.engage(clonedBoatman);

    cout << "====================Shields vs Shields====================" << endl;
    shieldBearerSoldier.engage(clonedShield);

    cout << "===================================================" << endl;
    cout << "Here are the stats of the shield bearers after the fight: " << endl;
    cout << "Name: " << shieldBearerSoldier.getName() << endl;
    cout << "Health " << shieldBearerSoldier.getHealth() << endl;
    cout << "Damage: " << shieldBearerSoldier.getDamage() << endl;
    cout << "Defence: " << shieldBearerSoldier.getDefence() << endl;
    cout << "Amount: " << shieldBearerSoldier.getAmt() << endl << endl;


    cout << "===================================================" << endl;
    cout << "Here are the stats of the boatmen before the fight: " << endl;
    cout << "Name: " << boatmanSoldier.getName() << endl;
    cout << "Health " << boatmanSoldier.getHealth() << endl;
    cout << "Damage: " << boatmanSoldier.getDamage() << endl;
    cout << "Defence: " << boatmanSoldier.getDefence() << endl;
    cout << "Amount: " << boatmanSoldier.getAmt() << endl << endl;

    cout << "====================Boatmen vs Infantry====================" << endl;
    boatmanSoldier.engage(clonedSoldier);

    cout << "====================Boatmen vs Boatmen====================" << endl;
    boatmanSoldier.engage(clonedBoatman);

    cout << "====================Boatmen vs Shield====================" << endl;
    boatmanSoldier.engage(clonedShield);

    cout << "===================================================" << endl;
    cout << "Here are the stats of the boatmen after the fight: " << endl;
    cout << "Name: " << boatmanSoldier.getName() << endl;
    cout << "Health " << boatmanSoldier.getHealth() << endl;
    cout << "Damage: " << boatmanSoldier.getDamage() << endl;
    cout << "Defence: " << boatmanSoldier.getDefence() << endl;
    cout << "Amount: " << boatmanSoldier.getAmt() << endl << endl;

}

void testFactories() {

}

int main() {
    testSoldiers();
    return 0;
};
