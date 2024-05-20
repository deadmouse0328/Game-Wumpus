#ifndef EVENT_H
#define EVENT_H 

//using namespace std;

//Event Interface
//Note: this must be an abstract class!

class Event
{

protected:
	

public:
    /*********************************************************************
    ** Function: percept
    ** Description: Abstract function to be overridden by derived classes.
    ** Parameters: None
    ** Pre-Conditions: Implemented in derived classes when the player is near an event.
    ** Post-Conditions: Specific event perception behavior is executed.
    *********************************************************************/
    // work when the player close to the events:
	virtual void percept() = 0;

    /*********************************************************************
    ** Function: encounter
    ** Description: Abstract function to be implemented in derived classes.
                    It specifies what happens when a player enters a room with an event.
    ** Parameters: None
    ** Pre-Conditions: Implemented in derived classes for when the player encounters the event.
    ** Post-Conditions: Executes the encounter behavior defined in the derived classes.
    *********************************************************************/
    //when the player get into the room, then encounter:
    virtual void encounter() = 0;

    /*********************************************************************
    ** Function: get_symbol
    ** Description: An abstract function that should be overridden in derived classes to
                    return a character symbol representing the specific event.
    ** Parameters: None
    ** Pre-Conditions: Implemented in derived classes to provide a symbol for the event.
    ** Post-Conditions: Returns a symbol character for the event.
    *********************************************************************/
    virtual char get_symbol() const = 0;


    virtual ~Event(){}
};
#endif