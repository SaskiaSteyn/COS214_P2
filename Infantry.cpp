#include "Infantry.h"

Infantry::Infantry(int health, int damage, int totalDamage, int defence, int amt, string name) : Soldiers(health, damage, totalDamage, defence, amt, name) {
    this->gunLoaded = false;
    this->hasGun = false;
    this->type = "Infantry";
}

Soldiers *Infantry::clonis() {
    Infantry * newInfantrySoldier = new Infantry(this->healthPerSoldier, this->damagePerSoldier, this->totalDamageCaused, this->defencePerSoldier, this->amountOfSoldiersPerUnit,
                                             this->unitName);
    newInfantrySoldier->hasGun = this->hasGun;
    newInfantrySoldier->gunLoaded = this->gunLoaded;

    newInfantrySoldier->enemy = this->enemy;
    newInfantrySoldier->fighting = this->fighting;

    return newInfantrySoldier;
}

void Infantry::prepare() {
    //Equips a shield
    this->hasGun = true;
    cout << this->unitName << " has equipped a weapon 🔫" << endl;
}

void Infantry::execute() {
    //Hold up shield to stop a blow or to block ammo
    this->gunLoaded = true;
    cout << this->unitName << " has raised their weapon" << endl;

    int tempDamage = this->enemy->dealDamage(this->getDamage());
    totalDamageCaused += tempDamage;
}

void Infantry::retreat() {
    //Walks backwards with shield still facing forward
    this->gunLoaded = false;
    cout << this->unitName << " has lowered their weapon" << endl;

}

void Infantry::rest(){
    //Hides behind shield and sits down
    this->hasGun = false;
    cout << this->unitName << " is resting" << endl;

}

int Infantry::getHealth() {
    return healthPerSoldier;
}

int Infantry::getAmt() {
    return amountOfSoldiersPerUnit;
}

int Infantry::getDamage() {
    return damagePerSoldier;
}

int Infantry::getTotalDamage() {
    return this->totalDamageCaused;
}

int Infantry::getDefence() {
    return defencePerSoldier;
}

int Infantry::dealDamage(int damageDealt) {
    if(this->enemy->getType() == "Boatman"){
        cout << this->unitName << " fought a Boatman soldier and won 🏆" << endl;
        healthPerSoldier -= damageDealt/2;

        cout << "Current health of " << this->unitName << " is: " << healthPerSoldier << endl;
        return damageDealt;
    }

    if(this->enemy->getType() == "ShieldBearer"){
        cout << this->unitName << " fought a Shield bearer and lost 😭" << endl;
        healthPerSoldier -= damageDealt*2;

        cout << "Current health of " << this->unitName << " is: " << healthPerSoldier << endl;
        return damageDealt;
    }

    if(this->enemy->getType() == "Infantry"){
        cout << this->unitName << " fought an Infantry soldier and they fought to a stalemate ⚔️" << endl;
        healthPerSoldier -= damageDealt;

        cout << "Current health of " << this->unitName << " is: " << healthPerSoldier << endl;
        return damageDealt;
    }

    return 0;
}

string Infantry::getName() {
    return this->unitName;
}
