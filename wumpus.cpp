
#include "wumpus.h"

#include <iostream>

using namespace std;

void Wumpus::percept() {
    cout << "You smell a terrible stench." << endl;
}

void Wumpus::encounter() {
    cout << "You encountered the Wumpus." << endl;
}

char Wumpus::get_symbol() const {
    return 'W';
}
Wumpus::~Wumpus(){}