#include "ShieldBearer.h"

ShieldBearer::ShieldBearer(int health, int damage, int totalDamage, int defence, int amt, string name) : Soldiers(health, damage, totalDamage, defence, amt, name) {
    this->shieldRaised = false;
    this->hasShield = false;
    this->type = "ShieldBearer";
}

Soldiers *ShieldBearer::clonis() {
    ShieldBearer * newShielBearer = new ShieldBearer(this->healthPerSoldier, this->damagePerSoldier, this->totalDamageCaused, this->defencePerSoldier, this->amountOfSoldiersPerUnit,
                                                     this->unitName);
    newShielBearer->hasShield = this->hasShield;
    newShielBearer->shieldRaised = this->shieldRaised;

    newShielBearer->enemy = this->enemy;
    newShielBearer->fighting = this->fighting;

    return newShielBearer;
}

void ShieldBearer::prepare() {
    //Equips a shield
    this->hasShield = true;
    cout << this->unitName << " has equipped a shield 🛡️" << endl;
}

void ShieldBearer::execute() {
    //Hold up shield to stop a blow or to block ammo
    this->shieldRaised = true;
    cout << this->unitName << " has raised their shield" << endl;

    int tempDamage = this->enemy->dealDamage(this->getDamage());
    totalDamageCaused += tempDamage;
}

void ShieldBearer::retreat() {
    //Walks backwards with shield still facing forward
    this->shieldRaised = false;
    cout << this->unitName << " has lowered their shield" << endl;

}

void ShieldBearer::rest(){
    //Hides behind shield and sits down
    this->hasShield = false;
    cout << this->unitName << " is resting" << endl;

}

int ShieldBearer::getHealth() {
    return healthPerSoldier;
}

int ShieldBearer::getAmt() {
    return amountOfSoldiersPerUnit;
}

int ShieldBearer::getDamage() {
    return damagePerSoldier;
}

int ShieldBearer::getTotalDamage() {
    return this->totalDamageCaused;
}

int ShieldBearer::getDefence() {
    return defencePerSoldier;
}

int ShieldBearer::dealDamage(int damageDealt) {
    if(this->enemy->getType() == "Infantry"){
        cout << this->unitName << " fought an Infantry soldier and won 🏆" << endl;
        healthPerSoldier -= damageDealt/2;

        cout << "Current health of " << this->unitName << " is: " << healthPerSoldier << endl;
        return damageDealt;
    }

    if(this->enemy->getType() == "Boatman"){
        cout << this->unitName << " fought a Boatman soldier and lost 😭" << endl;
        healthPerSoldier -= damageDealt*2;

        cout << "Current health of " << this->unitName << " is: " << healthPerSoldier << endl;
        return damageDealt;
    }

    if(this->enemy->getType() == "ShieldBearer"){
        cout << this->unitName << " fought a shield bearer and they fought to a stalemate ⚔️" << endl;
        healthPerSoldier -= damageDealt;

        cout << "Current health of " << this->unitName << " is: " << healthPerSoldier << endl;
        return damageDealt;
    }

    return 0;
}

string ShieldBearer::getName() {
    return this->unitName;
}



