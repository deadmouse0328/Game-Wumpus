
#ifndef STALACTITES_H
#define STALACTITES_H 

#include "event.h"

class Stalactites : public Event{
public:

    /*********************************************************************
    ** Function: percept
    ** Description: Shows a message when the player is near stalactites.
    ** Parameters: None
    ** Pre-Conditions: Player is close to stalactites.
    ** Post-Conditions: Displays a message about nearby stalactites.
    *********************************************************************/
    void percept() override;
    /*********************************************************************
    ** Function: encounter
    ** Description: Defines the event when the player comes across stalactites.
    ** Parameters: None
    ** Pre-Conditions: Player encounters stalactites.
    ** Post-Conditions: Triggers the stalactite encounter event.
    *********************************************************************/
    void encounter() override;

    /*********************************************************************
    ** Function: get_symbol
    ** Description: Provides the game symbol for stalactites.
    ** Parameters: None
    ** Pre-Conditions: Symbol for stalactites is needed.
    ** Post-Conditions: Returns the symbol representing stalactites.
    *********************************************************************/
    char get_symbol() const override;

};
#endif
