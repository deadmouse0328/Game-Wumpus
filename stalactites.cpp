
#include "stalactites.h"
#include <iostream>

using namespace std;

void Stalactites::percept(){
    cout << "You hear water dripping." << endl;
}

void Stalactites::encounter() {
    cout << "You see stalactites!" << endl;
}

char Stalactites::get_symbol() const {
    return 's';
}