
#ifndef ROOM_H
#define ROOM_H 

#include "event.h"

//using namespace std;

//Room Interface
//Note: Each room may be empty or has an event (bat, gold, pit, or wumpus);
//		Use event polymorphically

class Room
{
private:
//
	
public:
    // set one printer to event:
    Event* event;
/*********************************************************************
** Member: visited
** Description: Indicates whether the room has been visited by the player.
** Type: Bool
*********************************************************************/
    // then determine if the room ahs been visited or not:
    bool visited;

/*********************************************************************
** Constructor: Room
** Description: Initializes a Room object with no event and
                sets the room as not visited.
** Parameters: None
** Pre-Conditions: room object is being created.
** Post-Conditions: room is initialize with no event and marke unvisit
*********************************************************************/
    Room() : event(nullptr), visited(false) {}
    ~Room(){}
	

};

#endif