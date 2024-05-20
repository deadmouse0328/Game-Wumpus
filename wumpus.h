
#ifndef WUMPUS_H
#define WUMPUS_H 
#include "event.h"

class Wumpus : public Event{
public:
    // call the events abstract class:
    void percept() override;

    // the definition when encounter the wumpus:
    void encounter() override;

    char get_symbol() const override;

    ~Wumpus() override;
};

#endif