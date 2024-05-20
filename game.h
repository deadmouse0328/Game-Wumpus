
#ifndef GAME_H
#define GAME_H 

#include <vector>
#include <iostream> 
#include "room.h"

#include "event.h"
#include <utility>

//using namespace std;

//Game interface 
class Game
{
private:
	
	//declare a 2D vector of Room objects:

	//other member variables:
	int length; 			//length of the board
	int width;  			//width of the board
	int num_arrows; 		//keep track of number of errors remaining
	bool debug_view;		//debug mode or not

    /*********************************************************************
    ** Member: grid
    ** Description: A 2D vector representing the game board, consisting of Room objects.
    ** Type: 2D Vector of Room
    *********************************************************************/
    //vector:
    std::vector<std::vector<Room> > grid;

    /*********************************************************************
    ** Function: place_event
    ** Description: Places a specified number of a particular event on the game board.
    ** Pre-Conditions: The game board is initialized.
    ** Post-Conditions: Specified events are placed on the game board.
    *********************************************************************/
    void place_event(Event* event, int count);

    std::pair<int, int> player_position;
    std::pair<int, int> start_position;

    bool has_gold;

    bool is_confused;
    int confusion_remaining;

    bool game_over;


	//feel free to add more variables...

public:

	//suggested functions:
	Game();  //cons
	~Game(); //des

    /*********************************************************************
    ** Function: set_up
    ** Description: Sets up the game board and initializes game elements.
    ** Pre-Conditions: Game instance exists.
    ** Post-Conditions: Game board is set up and ready to play.
    *********************************************************************/
	void set_up(int, int);
    /*********************************************************************
    ** Function: display_game
    ** Description: Displays the current state of the game board.
    ** Pre-Conditions: Game is in progress.
    ** Post-Conditions: Current game state is displayed to the player.
    *********************************************************************/
	void display_game() const;
    /*********************************************************************
    ** Function: check_win
    ** Description: Checks if the player has met the win conditions of the game.
    ** Parameters: None
    ** Pre-Conditions: Game is in progress.
    ** Post-Conditions: Returns true if win conditions are met, otherwise false.
    *********************************************************************/
	bool check_win() const;

	char get_dir();
    /*********************************************************************
    ** Function: wumpus_move
    ** Description: Manages the movement of the Wumpus within the game.
    ** Pre-Conditions: The Wumpus is present in the game.
    ** Post-Conditions: The Wumpus has moved to a new location on the game board.
    *********************************************************************/
    void wumpus_move();
    /*********************************************************************
    ** Function: fire_arrow
    ** Description: Handles the player firing an arrow in a specified direction.
    ** Pre-Conditions: The player decides to fire an arrow and chooses a direction.
    ** Post-Conditions: The arrow is fired, affecting the game state depending on what it hits.
    *********************************************************************/

    void fire_arrow(char dir);

	void move_up();
	void move_down();
	void move_left();
	void move_right();
	void move(char);

	char get_input();
    /*********************************************************************
    ** Function: play_game
    ** Description: Starts and manages the main gameplay loop.
    ** Pre-Conditions: Game is initialized.
    ** Post-Conditions: Game is played until completion.
    *********************************************************************/
	void play_game(int, int, bool);
    /*********************************************************************
    ** Function: check_room_event
    ** Description: Checks and handles any event in the current room.
    ** Pre-Conditions: Player enters a new room.
    ** Post-Conditions: Any event in the room is handled.
    *********************************************************************/
    void check_room_event();
    /*********************************************************************
    ** Function: display_percepts
    ** Description: Displays hints or percepts for nearby events.
    ** Pre-Conditions: Game is in progress.
    ** Post-Conditions: Percepts for nearby events are displayed.
    *********************************************************************/
    void display_percepts() const;
	//feel free (and you will need) to add more functions...




};
#endif