// ----------------------------------------------------------
//     ('\''/').___..--'''`-._           _                   |
//     `9_ 9  )   `-.  (     ).`-.__.`) |_)                  |
//     (_Y_.)'  ._   )  `._ `. ``-..-'  |   |  _.     _  ._  |
//   _..`--'_..-_/  /--'_.' .'          |   | (_| \/ (/_ |   |
//  (il).-''  ((i).'  ((!.-'                      /          |
//                                                           |
// This Class contains player related functions and data, a  |
// Key handler detects keypresses and moves the player.      |
//                                                           |
// It also derives from the sprite class and contains        |
// functions that manage drawring the sprite on the screen.  |
// ----------------------------------------------------------

#ifndef PLAYER_H
#define PLAYER_H

#include "Sprites.h"
#include "Bomb.h"
#include "Arena.h"
#include <vector>

//set sprite class to be base class of player for acces to animation functions
class Player: public Sprites{

    public:

        Player(sf::RenderWindow &_window, Arena &_arenareference);

        ~Player();

        //players bomb handling class
         std::vector <Bomb* > handler;

         //reference object of RenderWindow for draw function
        sf::RenderWindow &win;

        //reference to arena object
        Arena &arenareference;

        //this remembers last direction or change in direction, also hand for switch
        enum direction{none, up, down, left , right};

        //this moves the player sprite and updates sprites location integers for collisons etc
        void movePlayer();

        //changes the heading value by detecting key inputs
        void keyInput();

        //this returns the players movement heading
        int getFace();

        //returns true if character is facing in a different direction since previously facing was updated
        bool newFace();

        void Draw();

        void drawBombs();

        bool arenaCheck(int, int, int, int);

        void arenaCheck();

        //sets arena reference pointer to arena
        void setArena(Arena arena);

        //returns reference to arena for operations
        Arena &getArena();

    private:

        //player one two etc
        int playerID;

        //position variables for player movement facing relates to enum direction(up, down ,left , right)
        //prevface is to store previously facing direction to avoid resetting animation loop and to create
        //special player move logic, next is player width and height, default 50 px for now
        int facing, previouslyFacing;

        //player may be able to customise their name
        std::string playerName;

};

#endif // PLAYER_H
