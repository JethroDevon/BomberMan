#include "Player.h"

//initialise window object and set sprites to be a base class of player, this way
//Sprites functions can be used by player class
Player::Player(sf::RenderWindow &_window): win(_window), Sprites("player.png", 4, 6){

    //sets base classes idle frame
    idle = 6;
    setPos( 100, 100);

}

Player::~Player(){
    //dtor
}

void Player::movePlayer(){

    if(!colliding){

        switch(facing){

            case 0 :

                facing = none;
                //nothing just yet, might have idle anim
                break;

            case 1 :

                //set sprite animation for walking up
                loopMode(newFace(), 0, 6);

                //move sprite up incrementally
                movePos(0,-6);
                break;

            case 2 :

                //set sprite animation for walking down
                loopMode(newFace(), 6, 12);

                //move sprite down incrementally
                movePos(0,6);
                break;

            case 3 :

                 //set sprite animation for walking left
                loopMode(newFace(), 12, 18);

                //move sprite left incrementally
                movePos(-6,0);
                break;

            case 4 :

                 //set sprite animation for walking right
                loopMode(newFace(), 18, 24);

                //move sprite right incrementally
                movePos(6,0);
                break;
        }
    }
}

//detects key input and changes the value of the facing integer
void Player::keyInput(){

    //get direction character is facing
    getFace();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){

        // left key is pressed: move our character
        facing = up;
    }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){

        // left key is pressed: move our character
        facing = down;
    }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){

        // left key is pressed: move our character
        facing = left;
    }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){

        // left key is pressed: move our character
        facing = right;
    }else{

        //set direction to move player to none to stop player moving
        facing = none;
    }

    //this is seperate from the main block so player can walk and lay bombs
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){


        //add a new bomb to array, default bomb settings present for now
        facing = none;

        //creates a new bomb, the offsets of 45 are to draw the bomb in the center of the screen
        handler.push_back(new Bomb(getPosX() - 40 , getPosY() - 40, 5, 5));
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//         this is the player loop, it takes care of all functions that belong to                    ////
//                      the player object and will be drawn in main                                  ////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
                            void Player::Draw(){                                                       //
                                                                                                       //
                                keyInput();                                                            //
                                drawBombs();                                                           //
                                movePlayer();                                                          //
                                win.draw(getNext());                                                   //
                            }                                                                          //
/////////////////////////////////////////////////////////////////////////////////////////////////////////

//this returns the players movement heading
int Player::getFace(){

    return facing;
}

//returns true if players facing direction has changed since last call
 bool Player::newFace(){

    if(facing != previouslyFacing){

        previouslyFacing = facing;
        return true;
    }else{

        return false;
    }
}

//this function draws all the blocks on the screen
void Player::drawBombs(){

    //loops through the handler array that contains an array of bombs that belong to player
    for(auto f: handler){

        //draws image function referred to frame in sprites
        win.draw( f->bombFrame());
    }
}

