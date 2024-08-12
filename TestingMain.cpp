#include <iostream>

#include "Infantry.h"
#include "Boatman.h"
#include "ShieldBearer.h"

#include "Memento.h"
#include "Caretaker.h"

using namespace std;

void testSoldiers() {
    Infantry infantrySoldier(200, 40, 0, 12, 50, "Footmen");
    Boatman boatmanSoldier(200, 30, 0, 12, 50, "Sailor");
    ShieldBearer shieldBearerSoldier(200, 20, 0, 12, 50, "Shieldmaiden");

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
    cout << "Total Damage caused: " << infantrySoldier.getTotalDamage() << endl;
    cout << "Defence: " << infantrySoldier.getDefence() << endl;
    cout << "Amount: " << infantrySoldier.getAmt() << endl << endl;

    cout << "===================================================" << endl;
    cout << "Here are the stats of the copied soldier: " << endl;
    cout << "Name: " << clonedSoldier->getName() << endl;
    cout << "Health " << clonedSoldier->getHealth() << endl;
    cout << "Damage: " << clonedSoldier->getDamage() << endl;
    cout << "Total damage caused: " << clonedSoldier->getTotalDamage() << endl;
    cout << "Defence: " << clonedSoldier->getDefence() << endl;
    cout << "Amount: " << clonedSoldier->getAmt() << endl << endl;

    cout << "===================================================" << endl;
    cout << "The battle starts" << endl;


    cout << "===================================================" << endl;
    cout << "Here are the stats of the Infantry soldiers before the fight: " << endl;
    cout << "Name: " << infantrySoldier.getName() << endl;
    cout << "Health " << infantrySoldier.getHealth() << endl;
    cout << "Total damage caused: " << infantrySoldier.getTotalDamage() << endl;
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
    cout << "Total damage caused: " << infantrySoldier.getTotalDamage() << endl;
    cout << "Defence: " << infantrySoldier.getDefence() << endl;
    cout << "Amount: " << infantrySoldier.getAmt() << endl << endl;



    cout << "===================================================" << endl;
    cout << "Here are the stats of the shield bearers before the fight: " << endl;
    cout << "Name: " << shieldBearerSoldier.getName() << endl;
    cout << "Health " << shieldBearerSoldier.getHealth() << endl;
    cout << "Total damage caused: " << shieldBearerSoldier.getTotalDamage() << endl;
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
    cout << "Total damage caused: " << shieldBearerSoldier.getTotalDamage() << endl;
    cout << "Defence: " << shieldBearerSoldier.getDefence() << endl;
    cout << "Amount: " << shieldBearerSoldier.getAmt() << endl << endl;


    cout << "===================================================" << endl;
    cout << "Here are the stats of the boatmen before the fight: " << endl;
    cout << "Name: " << boatmanSoldier.getName() << endl;
    cout << "Health " << boatmanSoldier.getHealth() << endl;
    cout << "Total damage caused: " << boatmanSoldier.getTotalDamage() << endl;
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
    cout << "Total damage caused: " << boatmanSoldier.getTotalDamage() << endl;
    cout << "Defence: " << boatmanSoldier.getDefence() << endl;
    cout << "Amount: " << boatmanSoldier.getAmt() << endl << endl;

}

void testFactories() {
    Soldiers* infantrySoldier = new Infantry(200, 40, 0, 12, 50, "Footmen");
    Soldiers* boatmanSoldier = new Boatman(200, 30, 0, 12, 50, "Sailor");
    Soldiers* shieldBearerSoldier = new ShieldBearer(200, 20, 0, 12, 50, "Shieldmaiden");

    InfantryFactory infantryFactory(infantrySoldier);
    BoatmanFactory boatmanFactory(boatmanSoldier);
    ShieldBearerFactory shieldBearerFactory(shieldBearerSoldier);

    Soldiers* blueInfantry = infantryFactory.createUnit();
    Soldiers* blueBoatman = boatmanFactory.createUnit();
    Soldiers* blueShieldBearer = shieldBearerFactory.createUnit();

    cout << "====================Testing Factory====================" << endl << endl;

    cout << "=====Infantry factory:=====" << endl;
    cout << blueInfantry->getType() << endl;
    cout << "Total health in this unit: " << infantryFactory.calculateTotalHealthPerUnit() << endl;
    cout << "Total damage in this unit: " << infantryFactory.calculateTotalDamagePerUnit() << endl;
    cout << "Total defence in this unit: " << infantryFactory.calculateTotalDefencePerUnit() << endl << endl;

    cout << "=====Boatman factory:=====" << endl;
    cout << blueBoatman->getType() << endl;
    cout << "Total health in this unit: " << boatmanFactory.calculateTotalHealthPerUnit() << endl;
    cout << "Total damage in this unit: " << boatmanFactory.calculateTotalDamagePerUnit() << endl;
    cout << "Total defence in this unit: " << boatmanFactory.calculateTotalDefencePerUnit() << endl << endl;

    cout << "=====Shield bearer factory:=====" << endl;
    cout << blueShieldBearer->getType() << endl;
    cout << "Total health in this unit: " << shieldBearerFactory.calculateTotalHealthPerUnit() << endl;
    cout << "Total damage in this unit: " << shieldBearerFactory.calculateTotalDamagePerUnit() << endl;
    cout << "Total defence in this unit: " << shieldBearerFactory.calculateTotalDefencePerUnit() << endl << endl;
}

void testMentos() {
    Soldiers *infantrySoldier = new Infantry(200, 40, 0, 12, 50, "Footmen");

    Caretaker *caretaker = new Caretaker();

//    caretaker->addMemento(infantrySoldier->getHealth(), infantrySoldier->getDamage(), infantrySoldier->getTotalDamage(), infantrySoldier->getDefence(), infantrySoldier->getAmt(), infantrySoldier->getName());
    Memento *mento = infantrySoldier->militusMemento();

    cout << "Created a mento" << endl;

    caretaker->addMemento(mento->getHealth(), mento->getDamage(), mento->getTotalDamage(), mento->getDefence(),
                          mento->getAmt(), mento->getName());

    cout << "Added the mento" << endl;

    Memento* mento2 = new Memento(200, 30, 0, 12, 50, "Footmen");

    cout << "Created a second mento" << endl;

    caretaker->addMemento(mento2);

    cout << "Added the second mento" << endl;

    Memento* mento3 = caretaker->getMemento(0);

    infantrySoldier->vivificaMemento(mento3);

    cout << "Index of mento2: " << caretaker->getMementoIndex(mento2) << endl;

    mento3->setHealth(100);
    mento3->setDamage(20);
    mento3->setTotalDamage(0);
    mento3->setDefence(20);
    mento3->setAmt(10);
    mento3->setName("Test Mento");

    cout << mento3->printFunc();
}

int main() {
    testSoldiers();
    testFactories();
    testMentos();
    return 0;
};
