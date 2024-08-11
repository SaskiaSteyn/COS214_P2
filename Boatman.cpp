
#include "Boatman.h"

Boatman::Boatman(int health, int damage, int totalDamage, int defence, int amt, string name) : Soldiers(health, damage, totalDamage, defence, amt, name) {
    this->raisedOar = false;
    this->hasOar = false;
    this->type = "Boatman";
}

Soldiers *Boatman::clonis() {
    Boatman * newBoatmanSoldier = new Boatman(this->healthPerSoldier, this->damagePerSoldier, this->totalDamageCaused, this->defencePerSoldier, this->amountOfSoldiersPerUnit,
                                                     this->unitName);
    newBoatmanSoldier->hasOar = this->hasOar;
    newBoatmanSoldier->raisedOar = this->raisedOar;

    newBoatmanSoldier->enemy = this->enemy;
    newBoatmanSoldier->fighting = this->fighting;

    return newBoatmanSoldier;
}

void Boatman::prepare() {
    //Equips a shield
    this->hasOar = true;
    cout << this->unitName << " has equipped an oar ⛵️" << endl;
}

void Boatman::execute(Soldiers * attacker) {
    //Hold up shield to stop a blow or to block ammo
    this->raisedOar = true;
    cout << this->unitName << " has readied their oar" << endl;

    int tempDamage = this->enemy->dealDamage(this->getDamage(), attacker);
    totalDamageCaused += tempDamage;
}

void Boatman::retreat() {
    //Walks backwards with shield still facing forward
    this->raisedOar = false;
    cout << this->unitName << " has lowered their oar" << endl;

}

bool Boatman::rest(){
    //Hides behind shield and sits down
    this->hasOar = false;
    cout << this->unitName << " is resting" << endl;

    return true;

}

int Boatman::getHealth() {
    return healthPerSoldier;
}

int Boatman::getAmt() {
    return amountOfSoldiersPerUnit;
}

int Boatman::getDamage() {
    return damagePerSoldier;
}

int Boatman::getTotalDamage() {
    return this->totalDamageCaused;
}

int Boatman::getDefence() {
    return defencePerSoldier;
}

int Boatman::dealDamage(int damageDealt, Soldiers * attacker) {
    if(this == attacker){
        if(this->enemy->getType() == "ShieldBearer"){
            cout << this->unitName << " fought a shield bearer and won 🏆" << endl;

            enemy->setHealth(this->healthPerSoldier - (damageDealt * 2));

            cout << "Current health of " << this->unitName << " is: " << healthPerSoldier << endl;
            return damageDealt;
        }

        if(this->enemy->getType() == "Infantry"){
            cout << this->unitName << " fought an infantry soldier and lost 😭" << endl;

            enemy->setHealth(this->healthPerSoldier - damageDealt);

            cout << "Current health of " << this->unitName << " is: " << healthPerSoldier << endl;
            return damageDealt;
        }

        if(this->enemy->getType() == "Boatman"){
            cout << this->unitName << " fought another boatman and they fought to a stalemate ⚔️" << endl;

            enemy->setHealth(this->healthPerSoldier - damageDealt);

            cout << "Current health of " << this->unitName << " is: " << healthPerSoldier << endl;
            return damageDealt;
        }
    }
    else{
        if(this->enemy->getType() == "ShieldBearer"){
            cout << this->unitName << " fought a shield bearer and won 🏆" << endl;

            enemy->setHealth(this->healthPerSoldier - damageDealt);

            cout << "Current health of " << this->unitName << " is: " << healthPerSoldier << endl;
            return damageDealt;
        }

        if(this->enemy->getType() == "Infantry"){
            cout << this->unitName << " fought an infantry soldier and lost 😭" << endl;

            enemy->setHealth(this->healthPerSoldier - damageDealt / 2);

            cout << "Current health of " << this->unitName << " is: " << healthPerSoldier << endl;
            return damageDealt;
        }

        if(this->enemy->getType() == "Boatman"){
            cout << this->unitName << " fought another boatman and they fought to a stalemate ⚔️" << endl;

            enemy->setHealth(this->healthPerSoldier - (damageDealt / 2));

            cout << "Current health of " << this->unitName << " is: " << healthPerSoldier << endl;
            return damageDealt;
        }
    }


    return 0;
}

string Boatman::getName() {
    return this->unitName;
}


int Boatman::setAmount(int amount) {
    return this->amountOfSoldiersPerUnit = amount;
}

int Boatman::setHealth(int health) {
    return this->healthPerSoldier = health;
}

