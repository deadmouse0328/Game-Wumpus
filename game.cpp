#include "game.h"
#include "gold.h"
#include "stalactites.h"
#include "bats.h"
#include "wumpus.h"
#include <cstdlib>
#include <ctime>


#include <iostream>


using namespace std;

//Game Implementation

Game::Game() : game_over(false){
	//Game constructor
    //the default arrow num:
    this -> num_arrows = 3;

    //started point:
    this-> player_position = {0,0};
    start_position = {0, 0};

    //no gold:
    has_gold = false;

    //confusion state:
    is_confused = false;
    confusion_remaining = 0;



}

Game::~Game(){
	//Game destructor
	//Your code here:

}


void Game::set_up(int l, int w){
	//set up the game
	this->length = l;
	this->width = w;

	this->num_arrows = 3; 	//start with 3 arrows

	// Finish the remaining...
	//Your code here:
    grid.resize(length, std::vector<Room>(width));
	
	// Create the game board: 2D vector of Room objects

	// randomly insert events (2 bats, 2 stalactites, 1 wumpus, 1 gold)
	// into the board

    //random start location:
    srand(time(NULL));
    player_position.first = rand() % length;
    player_position.second = rand() % width;

    //ramdomly events:

    //1. wumpus:
    place_event(new Wumpus(), 1);
    place_event(new Bats(), 2);
    place_event(new Stalactites(), 2);
    place_event(new gold(), 1);

}

void Game::place_event(Event* event, int count) {
    while (count > 0){
        int x = rand() % length;
        int y = rand() % width;

        //make sure the start point do not have any events:
        if (x == player_position.first && y == player_position.second) {
            continue;
        }

        //check if the room have encounter or not:
        if (grid[x][y].event == nullptr){
            grid[x][y].event = event;
            count--;
        }
    }

}

//Note: you need to modify this function
void Game::display_game() const{
//	cout << endl << endl;
	cout << "Arrows remaining: " << num_arrows << endl;


    string line = " " + string(width * 5, '-');
    cout << line << endl;

//    line += "+";

    for (int i = 0; i < length; ++i) {
        cout << " ";
        for (int j = 0; j < width; ++j) {
            // Print double vertical bars as room separators, except before the first room
            if (j > 0) {
                cout << "||";
            }
            // Player, event, or empty space
            if (player_position.first == i && player_position.second == j) {
                cout << " * "; // player position
            } else if (debug_view && grid[i][j].event != nullptr) {
                cout << " " << grid[i][j].event->get_symbol() << " "; // in debug mode
            } else {
                cout << "   "; // Empty room
            }
        }
        cout << " " << endl; // No vertical bar at the end, just a closing space
        cout << line << endl; // Bottom border for each row
    }

}

//example output (when finished):
// --------------------
//  B || G || B ||   ||
// --------------------
//    || W ||   || S ||
// --------------------
//    ||   ||   || S ||
// --------------------
// *  ||   ||   ||   ||
// --------------------

bool Game::check_win() const{
	//check if game over/win
    Room current_room= grid[player_position.first][player_position.second];

    //define find gold or not, then return:
    if (has_gold && player_position == start_position){
        cout << "You found the gold and returned safely! You win!" << endl;
        return true;
    }

	return false;
}

//move direction:
void Game::move_up() {
    //reverse after confuse:
    if (is_confused) {
        if (player_position.first < length - 1){
            player_position.first++;
        }
        confusion_remaining --;
        //end states:
        if (confusion_remaining <= 0){
            is_confused = false;
        }
    } else {
        if (player_position.first > 0) {
            player_position.first--;
        } else {
            cout << "You can't move up anymore." << endl;
        }
    }
}

void Game::move_down() {

    if (is_confused) {
        if (player_position.first > 0){
            player_position.first--;
        }
        confusion_remaining--;
        if (confusion_remaining <= 0) {
            is_confused = false; // end
        }
    }else {
        if (player_position.first < length - 1) {
            player_position.first++;
        } else {
            cout << "You can't move down anymore." << endl;
        }
    }
}

void Game::move_left() {

    if (is_confused) {
        if (player_position.second < width - 1){
            player_position.second++;
        }
        confusion_remaining--;
        if (confusion_remaining <= 0) {
            is_confused = false;
        }
    } else {
        if (player_position.second > 0) {
            player_position.second--;
        } else {
            cout << "You can't move left anymore." << endl;
        }
    }
}

void Game::move_right() {

    if (is_confused) {
        if (player_position.second > 0){
            player_position.second--;
        }
        confusion_remaining--;
        if (confusion_remaining <= 0) {
            is_confused = false;
        }
    } else {

        if (player_position.second < width - 1) {
            player_position.second++;
        } else {
            cout << "You can't move right anymore." << endl;
        }
    }
}



//char Game::get_dir(){
//	//get direction of arrow:
//	char dir;
//	//Note: error checking is needed!!
//	//Your code here:
//	cout << "Fire an arrow...." << endl;
//	cout << "W-up" << endl;
//	cout << "A-left" << endl;
//	cout << "S-down" << endl;
//	cout << "D-right" << endl;
//
//
//	cout << "Enter direction: " << endl;
//	cin >> dir;
//	cin.ignore(256, '\n');
//
//	return dir;
//}


void Game::fire_arrow(char dir){
	// The player may fire arrow...
    num_arrows --;

    //the arrow flying path:
    std::pair<int, int> arrow_pos = player_position;
    //could hit wall:
    bool hit_wall = false;

    for (int i = 0; i < 3 && !hit_wall; i++){
        //change arrow position though direction:
        switch (dir) {
            case 'w':
                if (arrow_pos.first > 0){
                    arrow_pos.first--;
                } else {
                    hit_wall = true;
                }
                break;

            case 'a':
                if (arrow_pos.second > 0){
                    arrow_pos.second--;

                } else {
                    hit_wall = true;
                }
                break;

            case 's':
                if (arrow_pos.first < length - 1){
                    arrow_pos.first ++;

                } else {
                    hit_wall = true;
                }
                break;

            case 'd':
                if (arrow_pos.second < width - 1){
                    arrow_pos.second ++;

                } else {
                    hit_wall = true;
                }
                break;

        }

        // check the arrow hit the wumpus or not:
        Event* current_event = grid[arrow_pos.first][arrow_pos.second].event;
        if (!hit_wall && current_event != nullptr) {
            if (typeid(*current_event) == typeid(Wumpus)) {
                cout << "You hit the Wumpus! You win!" << endl;
                game_over = true;
                return;
            }
        }
    }

    wumpus_move();

    //if no arrows:
    if (num_arrows <= 0){
        cout << "You have no more arrows. Game Over." << endl;
        game_over = true;
    }
}

void Game::wumpus_move(){
    //after a missed arrow, 75% chance that the wumpus is moved to a different room
    //How to get 75%?
    //Hint: generate a random number from 0-3, if the number is not 0, then move

    // generate from 0 to 3:
    int chance= rand() % 4;
    //75%
    if (chance != 0){
        std::pair<int, int> new_pos;
        bool valid_pos = false;

        while (!valid_pos){
            new_pos.first = rand() % length;
            new_pos.second = rand() % width;

            //make sure the new position is not the current position:
            if (new_pos != player_position && grid[new_pos.first][new_pos.second].event == nullptr){
                valid_pos = true;
            }
        }

        //after move, clear the old wumpus:
        for (auto & row : grid){
            for (auto & room : row){
                if (room.event != nullptr && typeid( * (room.event)) == typeid(Wumpus)){
                    //clear wumpus:
                    room.event = nullptr;
                    break;
                }
            }
        }

        //wumpus on new pos:
        grid[new_pos.first][new_pos.second].event = new Wumpus();
    }
}

void Game::move(char c) {
    if (game_over){
        return;
    }
//    bool checked_room_event = false; （test)
	// Handle player's action: move or fire an arrow
	if (c == 'f'){
        char arrow_direction;
        cout << "Enter arrow direction (w, a, s, d): ";
        cin >> arrow_direction;
        fire_arrow(arrow_direction);
	} else {
        switch(c) {
            case 'w':
                move_up();
                break;
            case 'a':
                move_left();
                break;
            case 's':
                move_down();
                break;
            case 'd':
                move_right();
                break;
            }
            if (!game_over){
                check_room_event();
//                check_room_event = true; (test)
            }
            //check room:
	}
//    if (!checked_room_event && !game_over){
//        check_room_event();        (test)
//    }
}

char Game::get_input(){
	//get action, move direction or firing an arrow

	//Note: error checking is needed!!
	//Your code here:
	char c;

	cout << endl << endl << "Player move..." << endl << endl;
	cout << "W-up" << endl;
	cout << "A-left" << endl;
	cout << "S-down" << endl;
	cout << "D-right" << endl;
	cout << "f-fire an arrow" << endl;

	cout << "Enter input: " << endl;
	cin >> c;
	cin.ignore(256, '\n');

	
	return c;
}


void Game::check_room_event(){
    Room& current_room = grid[player_position.first][player_position.second];

    //define player encounter wumpus or not:
    if (current_room.event != nullptr && typeid(*(current_room.event)) == typeid(Wumpus)) {
        cout << "You encountered the Wumpus! Game over." << endl;
        game_over = true;
        return;
    }


    // stalactites fall （50% chance)
    if (current_room.event != nullptr && typeid(*(current_room.event)) == typeid(Stalactites)){
        int chance = rand() % 100;
        if (chance < 50){
            cout << "The stalactites drop on you! Game Over." << endl;
            game_over = true;
            return;
        }
    }

    //find gold:
    if (current_room.event != nullptr && typeid(*(current_room.event)) == typeid(gold)){
        has_gold = true;
        cout << "You find gold!" << endl;
//        remove the symbol 'G'
        current_room.event = nullptr;
    }


    //encounter bats, change confuse states:
    if (current_room.event != nullptr) {
        if (typeid(*(current_room.event)) == typeid(Bats) && !is_confused) {
            is_confused = true;
            confusion_remaining = 5;
            cout << "You encountered super bats! You are now confused." << endl;

        }
    }


}



//Note: you need to modify this function
void Game::play_game(int w, int l, bool d){

	set_up(w, l);
	this->debug_view = d;
    game_over = false;

	while (!game_over && !check_win()){
		//print game board
		display_game();
        //show the surround hidden infomaiton.
        display_percepts();
		//display percerts around player's location
		//Your code here:

		//Player move...
		//1. get input
        char input = get_input();
        move(input);

		//2. move player
//		Game::move(input);

		//3. may or may not encounter events
		//Your code here:

        check_room_event();

        if (game_over) {
            break;
        }
	}

}

void Game::display_percepts() const{
    //check four direction of the room:
    std::pair<int, int> directions[4] = {
            {player_position.first - 1, player_position.second}, //north
            {player_position.first, player_position.second +1}, //east
            {player_position.first + 1, player_position.second}, //south
            {player_position.first, player_position.second - 1} //west
    };

    for (const auto & dir : directions){
        //check the edge:
        if (dir.first >= 0 && dir.first < length && dir.second >= 0 && dir.second < width) {
            const Room adjacent_room = grid[dir.first][dir.second];
            if (adjacent_room.event != nullptr) {
                // if pick up gold, don't show the percept again:
                if (typeid(* (adjacent_room.event)) == typeid(gold) && has_gold){
                    continue;
                }
                adjacent_room.event->percept();

            }
        }
    }
}