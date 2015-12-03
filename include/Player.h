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
#include <ctime>

//set sprite class to be base class of player for acces to animation functions
class Player: public Sprites{

    public:

        Player(sf::RenderWindow &_window);

        ~Player();

        //players bomb handling class is a set of pointers so
        //changes can be made to the objects dynamically
         std::vector <Bomb* > handler;

         void garbage();

         //reference object of RenderWindow for draw function
        sf::RenderWindow &win;

        //reference to arena object
        Arena *arenareference;

        //this remembers last direction or change in direction, also hand for switch
        enum direction{none, up, down, left , right};

        //this moves the player sprite and updates sprites location integers for collisons etc
        void movePlayer();

        //changes the heading value by detecting key inputs
        void keyInput(sf::Event);
        void keyInput();

        //this returns the players movement heading
        int getFace();

        //returns true if character is facing in a different direction since previously facing was updated
        bool newFace();

        void Draw();

        void drawBombs();

        bool arenaCheck(Sprites, bool);

        //sets arena reference pointer to arena
        void setArena(Arena &arena);

        void drawBlast();

        void initBlast(bool, int, int, int);

        void doBlast();

        int getBlastX();

        int getBlastY();

        int getFlame();

        //sets isAlive bool t ofalse
        void setDeath(bool _d);

        //returns wether or not player is dead
        bool getDeath();

        void collideBlast( std::vector <Bomb* >, Sprites);
        void igniteBlast(std::vector <Bomb* >);

        void layBomb();

        //these are the four directions the player can move
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();

    private:

        //position variables for player movement facing relates to enum direction(up, down ,left , right)
        //prevface is to store previously facing direction to avoid resetting animation loop and to create
        //special player move logic, flame blastX and blastY store position of next place to draw the blast of a bomb
        //layout specifies which keyboard layout to use.
        int facing, previouslyFacing, flame, blastX, blastY, layout;

        //blastflag is set to true in initBlast and set false again in do blast, when true, draws a bomb in stored positions
        //is alive isto check if the player is dead or not
        bool blastFlag, isAlive;

};

#endif // PLAYER_H
