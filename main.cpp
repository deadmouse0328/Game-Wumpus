/*********************************************************************
** Filename: main.cpp
** Author: Yanghui Ren
** Date: 11/28
** Description: Main driver of the Hunt the Wumpus game. Initializes and starts the game.
*********************************************************************/


#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"

using namespace std;


int main()
{
    //set the random seed
    srand(time(NULL));

    //input cave size:
    int width, length;
    cout << "Enter width of the cave (min 4, max 50): ";
    cin >> width;
    cout << "Enter length of the cave (min 4, max 50): ";
    cin >> length;

    if (width < 4 || width > 50 || length < 4 || length > 50){
        cout << "Invalid cave size, please run the program again and input the valid cave size." << endl;
        return 1;
    }

    //debug request, debug mode or not:
    bool debug = false;
    char debug_choice;
    cout << "Open debug mode? input (y/n): " << endl;
    cin >> debug_choice;

    if (debug_choice == 'y') {
        debug = true;
    } else if(debug_choice == 'n'){
        debug = false;
    } else {
        cout << "Invalid choice, please run the program again and input the valid debug mode." << endl;
        return 1;
    }

    //play game:
    Game game;
    game.play_game(width, length, debug);

    return 0;
}
