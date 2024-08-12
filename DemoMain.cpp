#include <iostream>
#include <vector>
#include <cctype>
#include <cstdlib>

#include "Soldiers.h"

#include "Infantry.h"
#include "ShieldBearer.h"
#include "Boatman.h"

#include "InfantryFactory.h"
#include "ShieldBearerFactory.h"
#include "BoatmanFactory.h"

using namespace std;

Soldiers** setBlueArmy(InfantryFactory &blueInfantryFactory, BoatmanFactory &blueBoatmanFactory, ShieldBearerFactory &blueShieldBearerFactory, int &blueUnits, Soldiers** blueArmy) {
    cout << "Blue Army" << endl;
    cout << "--------------------------" << endl;

    bool indeces[5];
    for (bool item: indeces) {
        item = false;
    }

    while (blueUnits != 0) {

        int index = rand() % 5;
        while (indeces[index]) {
            index = rand() % 5;
        }

        indeces[index] = true;

        cout << "You have " << blueUnits << " units remaining" << endl;

        string unitType;

        while ((unitType != "infantry") && (unitType != "boatman") && (unitType != "shieldbearer")) {

            cout << "Choose a type of unit to add:\t(Infantry | ShieldBearer | Boatman)" << endl;

            cin >> unitType;
//            cout << unitType << endl;

            for (char& c: unitType) {
                c = tolower(c);
            }

            if ((unitType != "infantry") && (unitType != "boatman") && (unitType != "shieldbearer")) {
                cout << "Please insert one of the following unit names" << endl;
            }
        }

        int numUnits = 0;

        while (numUnits < 1 || numUnits > blueUnits) {
            cout << "How many " << unitType << " units do you want: ";

            cin >> numUnits;

            if (blueUnits - numUnits < 0) {
                cout << "You do not have enough units. You only have " << blueUnits << " left." << endl;
            }
            if (numUnits < 1) {
                cout << "Please enter a positive number" << endl;
            }
        }



        if (unitType == "infantry") {
            blueArmy[index] = blueInfantryFactory.createUnit();
            blueArmy[index]->setAmount(numUnits);
        }
        else if (unitType == "shieldbearer") {
            blueArmy[index] = blueShieldBearerFactory.createUnit();
            blueArmy[index]->setAmount(numUnits);
        }
        else {
            blueArmy[index] = blueBoatmanFactory.createUnit();
            blueArmy[index]->setAmount(numUnits);
        }

        blueUnits -= numUnits;
    }

    return blueArmy;
}

Soldiers** setRedArmy(InfantryFactory &redInfantryFactory, BoatmanFactory &redBoatmanFactory, ShieldBearerFactory &redShieldBearerFactory, int &redUnits, Soldiers** redArmy) {
    cout << "Red Army" << endl;
    cout << "--------------------------" << endl;

    bool indeces[5];
    for (int i = 0; i < 5; i++) {
        indeces[i] = false;
    }

    while (redUnits != 0) {

        int index = rand() % 5;
        while (indeces[index]) {
            index = rand() % 5;
        }

        indeces[index] = true;

        cout << "You have " << redUnits << " units remaining" << endl;

        string unitType = "";

        while ((unitType != "infantry") && (unitType != "boatman") && (unitType != "shieldbearer")) {

            cout << "Choose a type of unit to add:\t(Infantry | ShieldBearer | Boatman)" << endl;

            cin >> unitType;
            cout << unitType << endl;

            for (char& c: unitType) {
                c = tolower(c);
            }

            if ((unitType != "infantry") && (unitType != "boatman") && (unitType != "shieldbearer")) {
                cout << "Please insert one of the following unit names" << endl;
            }
        }

        int numUnits = 0;

        while (numUnits < 1 || numUnits > redUnits) {
            cout << "How many " << unitType << " units do you want: ";

            cin >> numUnits;

            if (redUnits - numUnits < 0) {
                cout << "You do not have enough units. You only have " << redUnits << " left." << endl;
            }
            if (numUnits < 1) {
                cout << "Please enter a positive number" << endl;
            }
        }

//        cout << "Finished making the army" << endl;


        if (unitType == "infantry") {
            redArmy[index] = redInfantryFactory.createUnit();
            redArmy[index]->setAmount(numUnits);
        }
        else if (unitType == "shieldbearer") {
            redArmy[index] = redShieldBearerFactory.createUnit();
            redArmy[index]->setAmount(numUnits);
        }
        else {
            redArmy[index] = redBoatmanFactory.createUnit();
            redArmy[index]->setAmount(numUnits);
        }

        redUnits -= numUnits;
    }

    return redArmy;
}

bool shouldGameContinue(Soldiers*** gameMap) {

    int alive = 0;

    for (int i = 0; i < 5; i++) {
        if(gameMap[i] != nullptr) {
            alive++;
        }
    }

    return alive == 2;
}

bool inRange(Soldiers*** gameMap, int myPos) {
    for (int i = 0; i < 5; i++) {
        // If enemy is adjacent to me
        if (gameMap[i] != nullptr && i != myPos && (myPos - i == 1 || myPos - i == -1)) {
            return true;
        }
    }

    return false;
}

string getAction1(Soldiers*** gameMap, int myPos) {
//    cout << "In the getAction function" << endl;
    cout << "Action 1:" << endl;

    string action = "";

    while (action != "attack" && action != "move" && action != "rest") {
        if (inRange(gameMap, myPos)) {
            cout << "Choose an action:\t(Attack | Move | Rest)" << endl;

            cin >> action;
        }
        else {
            cout << "Choose an action:\t(Move | Rest)" << endl;

            cin >> action;
        }

        for (char& c: action) {
            c = tolower(c);
        }
    }

    return action;
}

string getAction2(Soldiers*** gameMap, int myPos, string prevMove) {
    cout << "Action 2:" << endl;
    string action = "";

    while (action != "attack" && action != "move" && action != "rest") {
        if (prevMove == "rest") {
            return "skip";
        }
        if (prevMove == "attack") {
            cout << "Choose an action:\t(Move | Rest)" << endl;

            cin >> action;
        }
        else if (prevMove == "move") {
            cout << "Choose an action:\t(Attack | Move | Rest)" << endl;

            cin >> action;
        }

        for (char& c: action) {
            c = tolower(c);
        }
    }

    return action;
}

bool hasHealth(Soldiers***gameMap, int teamPos) {
    for (int i = 0; i < 5; i++) {
        if (gameMap[teamPos][i] != nullptr && gameMap[teamPos][i]->getHealth() > 0) {
            return true;
        }
    }

    return false;
}

void generateMap(Soldiers*** gameMap, int bluePos, int redPos, int blueMana, int redMana) {

    cout << endl << "Blue Mana = " << blueMana << "\t Red Mana = " << redMana;
    cout << endl << "================" << endl;

    cout << "| ";

    for (int i = 0; i < 5; i++) {
        if (gameMap[i] == nullptr) {
            cout << "   ";
        }
        else if (i == bluePos){
            cout << " B ";
        }
        else if (i == redPos) {
            cout << " R ";
        }
    }

    cout << " |" << endl;

    cout << "| ";
    for (int i = 0; i < 5; i++) {
        cout << " ^ ";
    }
    cout << " |";

    cout << endl << "================" << endl;
}

int main() {

//    const string RESET = "\033[0m";
//    const string RED = "\033[31m";
//    const string GREEN = "\033[32m";
//    const string YELLOW = "\033[33m";
//    const string BLUE = "\033[34m";
//    const string MAGENTA = "\033[35m";
//    const string CYAN = "\033[36m";

    Infantry *blueInfantry = new Infantry(200, 40, 0, 12, 50, "Hoplite");
    Boatman *blueBoatman = new Boatman(200, 30, 0, 12, 50, "Trireme Oarsmen");
    ShieldBearer *blueShieldBearer = new ShieldBearer(200, 20, 0, 12, 50, "Myrmidon");

    Infantry *redInfantry = new Infantry(200, 40, 0, 12, 50, "Legionary");
    Boatman *redBoatman = new Boatman(200, 30, 0, 12, 50, "Quinquereme Rowers");
    ShieldBearer *redShieldBearer = new ShieldBearer(200, 20, 0, 12, 50, "Praetorian Guard");

    InfantryFactory blueInfantryFactory(blueInfantry);
    BoatmanFactory blueBoatmanFactory(blueBoatman);
    ShieldBearerFactory blueShieldBearerFactory(blueShieldBearer);


    InfantryFactory redInfantryFactory(redInfantry);
    BoatmanFactory redBoatmanFactory(redBoatman);
    ShieldBearerFactory redShieldBearerFactory(redShieldBearer);

    int blueUnits = 100;
    int redUnits = 100;

//    cout << "Done making the armies" << endl;

//    Soldiers** blueArmy = new Soldiers*[5];
//    Soldiers** redArmy = new Soldiers*[5];

    Soldiers** blueArmy = setBlueArmy(blueInfantryFactory, blueBoatmanFactory, blueShieldBearerFactory, blueUnits, new Soldiers*[5]);

    cout << "==============================" << endl;

    Soldiers** redArmy = setRedArmy(redInfantryFactory, redBoatmanFactory, redShieldBearerFactory, redUnits, new Soldiers*[5]);

//    cout << blueArmy[0]->getName() << endl;

    int blueMana = 100;
    int redMana = 100;

    Soldiers*** gameMap = new Soldiers ** [5];

    gameMap[0] = nullptr;
    gameMap[1] = new Soldiers*[5];
    gameMap[2] = nullptr;
    gameMap[3] = new Soldiers*[5];
    gameMap[4] = nullptr;

    for (int i = 0; i < 5; i++) {
        if (blueArmy[i] != nullptr) {
            gameMap[1][i] = blueArmy[i];
        }
        else {
            gameMap[1][i] = nullptr;
        }
        if (redArmy[i] != nullptr) {
            gameMap[3][i] = redArmy[i];
        }
        else {
            gameMap[3][i] = nullptr;
        }

    }
    


    //TODO: this has a bad access. Error message: EXC_BAD_ACCESS (code=1, address=0x30)

    // Start game

    bool teamTurn = true;

    int bluePos = 1;
    int redPos = 3;
    int troopNoBlue = rand() % 5;
    int troopNoRed = rand() % 5;

    generateMap(gameMap, bluePos, redPos, blueMana, redMana);

    // Randomly chooses a unit that is alive to fight
    //TODO:May need to change the data structure of gameMap or blueArmy and redArmy. Infinite loop here

//    for (int i = 0; i < 5; i++) {
//        cout << gameMap[bluePos][i] << endl;
//    }


    if (hasHealth(gameMap, bluePos)) {
        while (gameMap[bluePos][troopNoBlue] != nullptr && gameMap[bluePos][troopNoBlue]->getHealth() <= 0) {
            troopNoBlue = rand() % 5;
        }
    }
    else {
        cout << "Blue Team is defeated. Red team wins!" << endl;
        return 0;
    }

    if (hasHealth(gameMap, redPos)) {
        while (gameMap[redPos][troopNoRed] != nullptr && gameMap[redPos][troopNoRed]->getHealth() <= 0) {
            troopNoRed = rand() % 5;
        }
    }
    else {
        cout << "Red Team is defeated. Blue team wins!" << endl;
        return 0;
    }

    while (shouldGameContinue(gameMap)) {
        if (teamTurn) {

            cout << "----------------" << endl;
            cout << "Blue Team's Turn" << endl;
            cout << "----------------" << endl;

            // Action 1
            //TODO:Output the map here
            generateMap(gameMap, bluePos, redPos, blueMana, redMana);

//            cout << "Playing action now" << endl;

            string action1 = getAction1(gameMap, bluePos);

//            cout << "Played action 1" << endl;

            if (action1 == "rest") {
                if (gameMap[bluePos][troopNoBlue]->getName() == "Hoplite") {
                    blueMana += 60;
                }
                if (gameMap[bluePos][troopNoBlue]->getName() == "Trireme Oarsmen") {
                    blueMana += 30;
                }
                if (gameMap[bluePos][troopNoBlue]->getName() == "Myrmidon") {
                    blueMana += 15;
                }
                if (blueMana >= 100) {
                    blueMana = 100;
                }
            }
            else if (action1 == "attack") {
                if (inRange(gameMap, bluePos)) {

                    if (gameMap[bluePos][troopNoBlue]->getName() == "Hoplite" && blueMana < 40) {
                        cout << "Don't have enough mana. End of action" << endl;
                        break;
                    }
                    if (gameMap[bluePos][troopNoBlue]->getName() == "Trireme Oarsmen" && blueMana < 20) {
                        cout << "Don't have enough mana. End of action" << endl;
                        break;
                    }
                    if (gameMap[bluePos][troopNoBlue]->getName() == "Myrmidon" && blueMana < 10) {
                        cout << "Don't have enough mana. End of action" << endl;
                        break;
                    }

                    gameMap[bluePos][troopNoBlue]->engage(gameMap[redPos][troopNoRed]);

                    if (gameMap[bluePos][troopNoBlue]->getHealth() <= 0) {
                        gameMap[bluePos][troopNoBlue]->setAmount(0);
                    }
                    if (gameMap[redPos][troopNoRed]->getHealth() <= 0) {
                        gameMap[redPos][troopNoRed]->setAmount(0);
                    }
                }
                else {
                    cout << "Enemy is not in range" << endl;
                }
            }
            else if (action1 == "move") {
                bool canLeft = true;
                bool canRight = true;

                if (bluePos < 1) {
                    canLeft = false;
                }

                if (bluePos > 3) {
                    canRight = false;
                }

                if (canLeft && gameMap[bluePos - 1] != nullptr) {
                    canLeft = false;
                }

                if (canRight && gameMap[bluePos + 1] != nullptr) {
                    canRight = false;
                }

                if (canLeft && canRight) {
                    cout << "Move left or right?\t(L | R)" << endl;

                    string movement = "";
                    cin >> movement;

                    for (char& c: movement) {
                        c = tolower(c);
                    }

                    if (movement == "l" && bluePos > 0) {
                        gameMap[bluePos - 1] = gameMap[bluePos];
                        gameMap[bluePos] = nullptr;
                        bluePos--;
                    }
                    else if (movement == "r" && bluePos < 4) {
                        gameMap[bluePos + 1] = gameMap[bluePos];
                        gameMap[bluePos] = nullptr;
                        bluePos++;
                    }
                }
                else if (!canLeft && canRight) {
                    cout << "Moved right" << endl;
                    gameMap[bluePos + 1] = gameMap[bluePos];
                    gameMap[bluePos] = nullptr;
                    bluePos++;
                }
                else if (canLeft && canRight) {
                    cout << "Moved left" << endl;
                    gameMap[bluePos - 1] = gameMap[bluePos];
                    gameMap[bluePos] = nullptr;
                    bluePos--;
                }
                else {
                    cout << "Cannot move. End of turn" << endl;
                }
            }

            // End of action 1

            // Action 2
            //TODO:Output the map here
            generateMap(gameMap, bluePos, redPos, blueMana, redMana);

            string action2 = getAction2(gameMap, bluePos, action1);

            if (action2 == "rest") {
                if (gameMap[bluePos][troopNoBlue]->getName() == "Hoplite") {
                    blueMana += 30;
                }
                if (gameMap[bluePos][troopNoBlue]->getName() == "Trireme Oarsmen") {
                    blueMana += 20;
                }
                if (gameMap[bluePos][troopNoBlue]->getName() == "Myrmidon") {
                    blueMana += 10;
                }
                if (blueMana >= 100) {
                    blueMana = 100;
                }
            }
            else if (action2 == "attack") {
                if (inRange(gameMap, bluePos)) {
                    if (gameMap[bluePos][troopNoBlue]->getName() == "Hoplite" && blueMana < 40) {
                        cout << "Don't have enough mana. End of action" << endl;
                        break;
                    }
                    if (gameMap[bluePos][troopNoBlue]->getName() == "Trireme Oarsmen" && blueMana < 20) {
                        cout << "Don't have enough mana. End of action" << endl;
                        break;
                    }
                    if (gameMap[bluePos][troopNoBlue]->getName() == "Myrmidon" && blueMana < 10) {
                        cout << "Don't have enough mana. End of action" << endl;
                        break;
                    }

                    gameMap[bluePos][troopNoBlue]->engage(gameMap[redPos][troopNoRed]);

                    if (gameMap[bluePos][troopNoBlue]->getHealth() <= 0) {
                        gameMap[bluePos][troopNoBlue]->setAmount(0);
                    }
                    if (gameMap[redPos][troopNoRed]->getHealth() <= 0) {
                        gameMap[redPos][troopNoRed]->setAmount(0);
                    }
                }
                else {
                    cout << "Enemy is not in range" << endl;
                }
            }
            else if (action2 == "move") {
                bool canLeft = true;
                bool canRight = true;

                if (bluePos < 1) {
                    canLeft = false;
                }

                if (bluePos > 3) {
                    canRight = false;
                }

                if (canLeft && gameMap[bluePos - 1] != nullptr) {
                    canLeft = false;
                }

                if (canRight && gameMap[bluePos + 1] != nullptr) {
                    canRight = false;
                }

                if (canLeft && canRight) {
                    cout << "Move left or right?\t(L | R)" << endl;

                    string movement = "";
                    cin >> movement;

                    for (char& c: movement) {
                        c = tolower(c);
                    }

                    if (movement == "l" && bluePos > 0) {
                        gameMap[bluePos - 1] = gameMap[bluePos];
                        gameMap[bluePos] = nullptr;
                        bluePos--;
                    }
                    else if (movement == "r" && bluePos < 4) {
                        gameMap[bluePos + 1] = gameMap[bluePos];
                        gameMap[bluePos] = nullptr;
                        bluePos++;
                    }
                }
                else if (!canLeft && canRight) {
                    cout << "Moved right" << endl;
                    gameMap[bluePos + 1] = gameMap[bluePos];
                    gameMap[bluePos] = nullptr;
                    bluePos++;
                }
                else if (canLeft && canRight) {
                    cout << "Moved left" << endl;
                    gameMap[bluePos - 1] = gameMap[bluePos];
                    gameMap[bluePos] = nullptr;
                    bluePos--;
                }
                else {
                    cout << "Cannot move. End of turn" << endl;
                }
            }
        }
        else {
            // Red Team

            cout << "----------------" << endl;
            cout << "Red Team's Turn" << endl;
            cout << "----------------" << endl;

            // Action 1
            //TODO:Output the map here
            generateMap(gameMap, bluePos, redPos, blueMana, redMana);

            string action1 = getAction1(gameMap, redPos);

            if (action1 == "rest") {
                if (gameMap[redPos][troopNoRed]->getName() == "Legionary") {
                    redMana += 45;
                }
                if (gameMap[redPos][troopNoRed]->getName() == "Quinquereme Rowers") {
                    redMana += 30;
                }
                if (gameMap[redPos][troopNoRed]->getName() == "Praetorian Guard") {
                    redMana += 15;
                }
                if (redMana >= 100) {
                    redMana = 100;
                }
            }
            else if (action1 == "attack") {
                if (inRange(gameMap, redPos)) {
                    if (gameMap[bluePos][troopNoBlue]->getName() == "Legionary" && blueMana < 40) {
                        cout << "Don't have enough mana. End of action" << endl;
                        break;
                    }
                    if (gameMap[bluePos][troopNoBlue]->getName() == "Quinquereme Rowers" && blueMana < 20) {
                        cout << "Don't have enough mana. End of action" << endl;
                        break;
                    }
                    if (gameMap[bluePos][troopNoBlue]->getName() == "Praetorian Guard" && blueMana < 10) {
                        cout << "Don't have enough mana. End of action" << endl;
                        break;
                    }

                    gameMap[redPos][troopNoRed]->engage(gameMap[bluePos][troopNoBlue]);

                    if (gameMap[bluePos][troopNoBlue]->getHealth() <= 0) {
                        gameMap[bluePos][troopNoBlue]->setAmount(0);
                    }
                    if (gameMap[redPos][troopNoRed]->getHealth() <= 0) {
                        gameMap[redPos][troopNoRed]->setAmount(0);
                    }
                }
                else {
                    cout << "Enemy is not in range" << endl;
                }
            }
            else if (action1 == "move") {
                bool canLeft = true;
                bool canRight = true;

                if (redPos < 1) {
                    canLeft = false;
                }

                if (redPos > 3) {
                    canRight = false;
                }

                if (canLeft && gameMap[redPos - 1] != nullptr) {
                    canLeft = false;
                }

                if (canRight && gameMap[redPos + 1] != nullptr) {
                    canRight = false;
                }

                if (canLeft && canRight) {
                    cout << "Move left or right?\t(L | R)" << endl;

                    string movement = "";
                    cin >> movement;

                    for (char& c: movement) {
                        c = tolower(c);
                    }

                    if (movement == "l" && redPos > 0) {
                        gameMap[redPos - 1] = gameMap[redPos];
                        gameMap[redPos] = nullptr;
                        redPos--;
                    }
                    else if (movement == "r" && redPos < 4) {
                        gameMap[redPos + 1] = gameMap[redPos];
                        gameMap[redPos] = nullptr;
                        redPos++;
                    }
                }
                else if (!canLeft && canRight) {
                    cout << "Moved right" << endl;
                    gameMap[redPos + 1] = gameMap[redPos];
                    gameMap[redPos] = nullptr;
                    redPos++;
                }
                else if (canLeft && canRight) {
                    cout << "Moved left" << endl;
                    gameMap[redPos - 1] = gameMap[redPos];
                    gameMap[redPos] = nullptr;
                    redPos--;
                }
                else {
                    cout << "Cannot move. End of turn" << endl;
                }
            }

            // End of action 1

            // Action 2
            //TODO:Output the map here
            generateMap(gameMap, bluePos, redPos, blueMana, redMana);

            string action2 = getAction2(gameMap, redPos, action1);

            if (action2 == "rest") {
                if (gameMap[redPos][troopNoRed]->getName() == "Legionary") {
                    redMana += 30;
                }
                if (gameMap[redPos][troopNoRed]->getName() == "Quinquereme Rowers") {
                    redMana += 20;
                }
                if (gameMap[redPos][troopNoRed]->getName() == "Praetorian Guard") {
                    redMana += 10;
                }
                if (redMana >= 100) {
                    redMana = 100;
                }
            }
            else if (action2 == "attack") {
                if (inRange(gameMap, redPos)) {
                    if (gameMap[bluePos][troopNoBlue]->getName() == "Legionary" && blueMana < 40) {
                        cout << "Don't have enough mana. End of action" << endl;
                        break;
                    }
                    if (gameMap[bluePos][troopNoBlue]->getName() == "Quinquereme Rowers" && blueMana < 20) {
                        cout << "Don't have enough mana. End of action" << endl;
                        break;
                    }
                    if (gameMap[bluePos][troopNoBlue]->getName() == "Praetorian Guard" && blueMana < 10) {
                        cout << "Don't have enough mana. End of action" << endl;
                        break;
                    }

                    gameMap[redPos][troopNoRed]->engage(gameMap[bluePos][troopNoBlue]);

                    if (gameMap[bluePos][troopNoBlue]->getHealth() <= 0) {
                        gameMap[bluePos][troopNoBlue]->setAmount(0);
                    }
                    if (gameMap[redPos][troopNoRed]->getHealth() <= 0) {
                        gameMap[redPos][troopNoRed]->setAmount(0);
                    }
                }
                else {
                    cout << "Enemy is not in range" << endl;
                }
            }
            else if (action2 == "move") {
                bool canLeft = true;
                bool canRight = true;

                if (redPos < 1) {
                    canLeft = false;
                }

                if (redPos > 3) {
                    canRight = false;
                }

                if (canLeft && gameMap[redPos - 1] != nullptr) {
                    canLeft = false;
                }

                if (canRight && gameMap[redPos + 1] != nullptr) {
                    canRight = false;
                }

                if (canLeft && canRight) {
                    cout << "Move left or right?\t(L | R)" << endl;

                    string movement = "";
                    cin >> movement;

                    for (char& c: movement) {
                        c = tolower(c);
                    }

                    if (movement == "l" && redPos > 0) {
                        gameMap[redPos - 1] = gameMap[redPos];
                        gameMap[redPos] = nullptr;
                        redPos--;
                    }
                    else if (movement == "r" && redPos < 4) {
                        gameMap[redPos + 1] = gameMap[redPos];
                        gameMap[redPos] = nullptr;
                        redPos++;
                    }
                }
                else if (!canLeft && canRight) {
                    cout << "Moved right" << endl;
                    gameMap[redPos + 1] = gameMap[redPos];
                    gameMap[redPos] = nullptr;
                    redPos++;
                }
                else if (canLeft && canRight) {
                    cout << "Moved left" << endl;
                    gameMap[redPos - 1] = gameMap[redPos];
                    gameMap[redPos] = nullptr;
                    redPos--;
                }
                else {
                    cout << "Cannot move. End of turn" << endl;
                }
            }
        }

        teamTurn = !teamTurn;

        if (hasHealth(gameMap, bluePos)) {
            while (gameMap[bluePos][troopNoBlue] != nullptr && gameMap[bluePos][troopNoBlue]->getHealth() <= 0) {
                troopNoBlue = rand() % 5;
            }
        }
        else {
            cout << "Blue Team is defeated. Red team wins!" << endl;
            return 0;
        }

        if (hasHealth(gameMap, redPos)) {
            while (gameMap[redPos][troopNoRed] != nullptr && gameMap[redPos][troopNoRed]->getHealth() <= 0) {
                troopNoRed = rand() % 5;
            }
        }
        else {
            cout << "Red Team is defeated. Blue team wins!" << endl;
            return 0;
        }
    }

}