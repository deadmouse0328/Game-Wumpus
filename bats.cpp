#include "bats.h"

#include <iostream>

using namespace std;

void Bats::percept() {
    cout << "You hear wings flapping." << endl;
}

void Bats::encounter() {
    cout << "You encountered super bats." << endl;
}

char Bats::get_symbol() const {
    return 'B';
}
