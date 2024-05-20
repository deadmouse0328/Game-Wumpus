
#include "gold.h"

#include <iostream>

using namespace std;

void gold::percept() {
    cout << "You see a glimmer nearby." << endl;
}

void gold::encounter() {
    cout << "You find out gold!" << endl;
}

char gold::get_symbol() const {
    return 'G';
}

