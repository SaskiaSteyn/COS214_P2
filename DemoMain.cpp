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

void setBlueArmy(InfantryFactory &blueInfantryFactory, BoatmanFactory &blueBoatmanFactory, ShieldBearerFactory &blueShieldBearerFactory, int &blueUnits, Soldiers* blueArmy[]) {
    cout << "Blue Army" << endl;
    cout << "--------------------------" << endl;

    bool indeces[5];
    for (int i = 0; i < 5; i++) {
        indeces[i] = false;
    }

    while (blueUnits != 0) {

        int index = rand() % 5;
        while (indeces[index]) {
            index = rand() % 5;
        }

        indeces[index] = true;

        cout << "You have " << blueUnits << " units remaining" << endl;

        string unitType = "";

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
                cout << "Not enough units" << endl;
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


}

void setRedArmy(InfantryFactory &redInfantryFactory, BoatmanFactory &redBoatmanFactory, ShieldBearerFactory &redShieldBearerFactory, int &redUnits, Soldiers* redArmy[]) {
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
                cout << "Not enough units" << endl;
            }
            if (numUnits < 1) {
                cout << "Please enter a positive number" << endl;
            }
        }



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


}

bool shouldGameContinue(Soldiers** gameMap) {

    int alive = 0;

    for (int i = 0; i < 5; i++) {
        if(gameMap[i] != nullptr) {
            alive++;
        }
    }

    return alive == 2;
}

bool inRange(Soldiers** gameMap, int myPos) {
    for (int i = 0; i < 5; i++) {
        // If enemy is adjacent to me
        if (gameMap[i] != nullptr && i != myPos && (myPos - i == 1 || myPos - i == -1)) {
            return true;
        }
    }

    return false;
}

string getAction1(Soldiers** gameMap, int myPos) {
    cout << "Action 1:" << endl;

    string action = "";

    while (action != "attack" || action != "move" || action != "rest") {
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

string getAction2(Soldiers** gameMap, int myPos, string prevMove) {
    cout << "Action 2:" << endl;
    string action = "";

    while (action != "attack" || action != "move" || action != "rest") {
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

bool hasHealth(Soldiers*army[], int index) {
    for (int i = 0; i < 5; i++) {
        if (army[i] != nullptr && army[i]->getHealth() > 0) {
            return true;
        }
    }

    return false;
}

void generateMap(Soldiers* gameMap[], Soldiers* blueArmy[]) {

//    const string RESET = "\033[0m";
//    const string RED = "\033[31m";
//    const string GREEN = "\033[32m";
//    const string YELLOW = "\033[33m";
//    const string BLUE = "\033[34m";
//    const string MAGENTA = "\033[35m";
//    const string CYAN = "\033[36m";
//    cout << "\033[33m" << "=================" << "\033[0m" << endl;

//    cout << YELLOW << "| " << RESET;
//
//    for (int i = 0; i < 5; i++) {
//        if (gameMap[i] == nullptr) {
//            cout << "  ";
//        }
//        else if (gameMap[i] == *blueArmy){
//            cout << " " << BLUE << "X" << RESET;
//        }
//        else {
//            cout << " " << RED << "X" << RESET;
//        }
//    }
//
//    cout << YELLOW << " |" << RESET << endl;
//
//    cout << YELLOW << "=================" << RESET << endl;

    cout << endl << "================" << endl;

    cout << "| ";

    for (int i = 0; i < 5; i++) {
        if (gameMap[i] == nullptr) {
            cout << "  ";
        }
        else if (gameMap[i] == *blueArmy){
            cout << " " << "B ";
        }
        else {
            cout << " " << "R ";
        }
    }

    cout << " |" << endl;

    cout << "================" << endl;
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

    Soldiers* blueArmy[5];
    Soldiers* redArmy[5];

    setBlueArmy(blueInfantryFactory, blueBoatmanFactory, blueShieldBearerFactory, blueUnits, blueArmy);

    cout << "==============================" << endl;

    setRedArmy(redInfantryFactory, redBoatmanFactory, redShieldBearerFactory, redUnits, redArmy);

    int blueMana = 100;
    int redMana = 100;

    Soldiers* gameMap[5];

    gameMap[0] = nullptr;
    gameMap[1] = *blueArmy;
    gameMap[2] = nullptr;
    gameMap[3] = *redArmy;
    gameMap[4] = nullptr;

    for (int i = 0; i < 5; i++) {
        if (blueArmy[i] != nullptr) {
            cout << blueArmy[i]->getName() << endl;
        }
    }

    generateMap(gameMap, blueArmy);

    // Start game

    bool teamTurn = true;

    int bluePos = 1;
    int redPos = 3;
    int troopNoBlue = rand() % 5;
    int troopNoRed = rand() % 5;

    // Randomly chooses a unit that is alive to fight
    //TODO:May need to change the data structure of gameMap or blueArmy and redArmy. Infinite loop here
    if (hasHealth(gameMap, bluePos)) {
        cout << "generating an index" << endl;

        while (gameMap[bluePos][troopNoBlue].getHealth() <= 0) {
            troopNoBlue = rand() % 5;
        }

        cout << "generated an index" << endl;
    }
    else {
        cout << "Blue Team is defeated. Red team wins!" << endl;
        return 0;
    }

    if (hasHealth(gameMap, redPos)) {
        while (gameMap[redPos][troopNoBlue].getHealth() <= 0) {
            troopNoRed = rand() % 5;
        }
    }
    else {
        cout << "Red Team is defeated. Blue team wins!" << endl;
        return 0;
    }

    while (shouldGameContinue(gameMap)) {
        if (teamTurn) {

            // Action 1
            //TODO:Output the map here


            string action1 = getAction1(gameMap, bluePos);

            if (action1 == "rest") {
                if (gameMap[bluePos][troopNoBlue].getName() == "Hoplite") {
                    blueMana += 45;
                }
                if (gameMap[bluePos][troopNoBlue].getName() == "Trireme Oarsmen") {
                    blueMana += 30;
                }
                if (gameMap[bluePos][troopNoBlue].getName() == "Myrmidon") {
                    blueMana += 15;
                }
                if (blueMana >= 100) {
                    blueMana = 100;
                }
            }
            else if (action1 == "attack") {
                if (inRange(gameMap, bluePos)) {
                    gameMap[bluePos][troopNoBlue].engage(&gameMap[redPos][troopNoRed]);

                    if (gameMap[bluePos][troopNoBlue].getHealth() <= 0) {
                        gameMap[bluePos][troopNoBlue].setAmount(0);
                    }
                    if (gameMap[redPos][troopNoRed].getHealth() <= 0) {
                        gameMap[redPos][troopNoRed].setAmount(0);
                    }
                }
                else {
                    cout << "Enemy is not in range" << endl;
                }
            }
            else if (action1 == "move") {
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

            // End of action 1

            // Action 2
            //TODO:Output the map here

            string action2 = getAction2(gameMap, bluePos, action1);

            if (action2 == "rest") {
                if (gameMap[bluePos][troopNoBlue].getName() == "Hoplite") {
                    blueMana += 30;
                }
                if (gameMap[bluePos][troopNoBlue].getName() == "Trireme Oarsmen") {
                    blueMana += 20;
                }
                if (gameMap[bluePos][troopNoBlue].getName() == "Myrmidon") {
                    blueMana += 10;
                }
                if (blueMana >= 100) {
                    blueMana = 100;
                }
            }
            else if (action2 == "attack") {
                if (inRange(gameMap, bluePos)) {
                    gameMap[bluePos][troopNoBlue].engage(&gameMap[redPos][troopNoRed]);

                    if (gameMap[bluePos][troopNoBlue].getHealth() <= 0) {
                        gameMap[bluePos][troopNoBlue].setAmount(0);
                    }
                    if (gameMap[redPos][troopNoRed].getHealth() <= 0) {
                        gameMap[redPos][troopNoRed].setAmount(0);
                    }
                }
                else {
                    cout << "Enemy is not in range" << endl;
                }
            }
            else if (action2 == "move") {
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
        }
        else {
            // Red Team

            // Action 1
            //TODO:Output the map here

            string action1 = getAction1(gameMap, redPos);

            if (action1 == "rest") {
                if (gameMap[redPos][troopNoRed].getName() == "Legionary") {
                    redMana += 45;
                }
                if (gameMap[redPos][troopNoRed].getName() == "Quinquereme Rowers") {
                    redMana += 30;
                }
                if (gameMap[redPos][troopNoRed].getName() == "Praetorian Guard") {
                    redMana += 15;
                }
                if (redMana >= 100) {
                    redMana = 100;
                }
            }
            else if (action1 == "attack") {
                if (inRange(gameMap, redPos)) {
                    gameMap[redPos][troopNoRed].engage(&gameMap[bluePos][troopNoBlue]);

                    if (gameMap[bluePos][troopNoBlue].getHealth() <= 0) {
                        gameMap[bluePos][troopNoBlue].setAmount(0);
                    }
                    if (gameMap[redPos][troopNoRed].getHealth() <= 0) {
                        gameMap[redPos][troopNoRed].setAmount(0);
                    }
                }
                else {
                    cout << "Enemy is not in range" << endl;
                }
            }
            else if (action1 == "move") {
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

            // End of action 1

            // Action 2
            //TODO:Output the map here

            string action2 = getAction2(gameMap, redPos, action1);

            if (action2 == "rest") {
                if (gameMap[redPos][troopNoRed].getName() == "Legionary") {
                    redMana += 30;
                }
                if (gameMap[redPos][troopNoRed].getName() == "Quinquereme Rowers") {
                    redMana += 20;
                }
                if (gameMap[redPos][troopNoRed].getName() == "Praetorian Guard") {
                    redMana += 10;
                }
                if (redMana >= 100) {
                    redMana = 100;
                }
            }
            else if (action2 == "attack") {
                if (inRange(gameMap, redPos)) {
                    gameMap[redPos][troopNoRed].engage(&gameMap[bluePos][troopNoBlue]);

                    if (gameMap[bluePos][troopNoBlue].getHealth() <= 0) {
                        gameMap[bluePos][troopNoBlue].setAmount(0);
                    }
                    if (gameMap[redPos][troopNoRed].getHealth() <= 0) {
                        gameMap[redPos][troopNoRed].setAmount(0);
                    }
                }
                else {
                    cout << "Enemy is not in range" << endl;
                }
            }
            else if (action2 == "move") {
                cout << "Move left or right?\t(L | R)" << endl;

                string movement = "";
                cin >> movement;

                for (char& c: movement) {
                    c = tolower(c);
                }

                if (movement == "l" && redPos > 0) {
                    gameMap[redPos - 1] = gameMap[redPos];
                    gameMap[redPos] = nullptr;
                    bluePos--;
                }
                else if (movement == "r" && redPos < 4) {
                    gameMap[redPos + 1] = gameMap[redPos];
                    gameMap[redPos] = nullptr;
                    redPos++;
                }
            }
        }

        teamTurn = !teamTurn;

        if (hasHealth(gameMap, bluePos)) {
            while (gameMap[bluePos][troopNoBlue].getHealth() <= 0) {
                troopNoBlue = rand() % 5;
            }
        }
        else {
            cout << "Blue Team is defeated. Red team wins!" << endl;
            return 0;
        }

        if (hasHealth(gameMap, redPos)) {
            while (gameMap[redPos][troopNoBlue].getHealth() <= 0) {
                troopNoRed = rand() % 5;
            }
        }
        else {
            cout << "Red Team is defeated. Blue team wins!" << endl;
            return 0;
        }
    }

}