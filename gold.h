
#ifndef GOLD_H
#define GOLD_H
#include "event.h"

class gold : public Event{
public:

    /*********************************************************************
    ** Function: percept
    ** Description: displaying a message or effect when the player is near
                    a gold object in the game.
    ** Parameters: None
    ** Pre-Conditions:  when the player is near a gold
    ** Post-Conditions: to the console
    *********************************************************************/
    void percept() override;

    /*********************************************************************
    ** Function: encounter
    ** Description: Defines what happens when the player finds gold.
    ** Parameters: None
    ** Pre-Conditions: Player finds gold.
    ** Post-Conditions: Game reacts to the player finding gold.
    *********************************************************************/
    void encounter() override;

    /*********************************************************************
    ** Function: get_symbol
    ** Description: Gives the symbol for gold in the game.
    ** Parameters: None
    ** Pre-Conditions: Need a symbol for gold.
    ** Post-Conditions: Returns the gold symbol.
    *********************************************************************/
    char get_symbol() const override;
};

#endif