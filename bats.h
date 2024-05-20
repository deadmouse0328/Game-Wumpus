#ifndef BATS_H
#define BATS_H 
#include "event.h"

class Bats : public Event{
public:

    /*********************************************************************
    ** Function: percept
    ** Description: Displays a message when the player is near bats.
    ** Parameters: None
    ** Pre-Conditions: Player is close to bats.
    ** Post-Conditions: Message about nearby bats is shown.
    *********************************************************************/
    void percept() override;

    /*********************************************************************
    ** Function: encounter
    ** Description: Details what occurs when the player encounters bats.
    ** Parameters: None
    ** Pre-Conditions: Player encounters bats.
    ** Post-Conditions: Game responds to the bat encounter.
    *********************************************************************/
    void encounter() override;

    /*********************************************************************
    ** Function: get_symbol
    ** Description: Returns the symbol representing bats in the game.
    ** Parameters: None
    ** Pre-Conditions: A symbol for bats is needed.
    ** Post-Conditions: Bat symbol is provided.
    *********************************************************************/
    char get_symbol() const override;
};


#endif