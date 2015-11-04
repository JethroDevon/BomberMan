#include "Player.h"

//initialise window object and set sprites to be a base class of player, this way
//Sprites functions can be used by player class
Player::Player(sf::RenderWindow &_window): win(_window), Sprites("player.png", 4, 6){

    //sets base classes idle frame
    idle = 6;
    setSpritePos( 100, 100);

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
                moveSprites(0,-6);
                break;

            case 2 :

                //set sprite animation for walking down
                loopMode(newFace(), 6, 12);

                //move sprite down incrementally
                moveSprites(0,6);
                break;

            case 3 :

                 //set sprite animation for walking left
                loopMode(newFace(), 12, 18);

                //move sprite left incrementally
                moveSprites(-6,0);
                break;

            case 4 :

                 //set sprite animation for walking right
                loopMode(newFace(), 18, 24);

                //move sprite right incrementally
                moveSprites(6,0);
                break;
        }
    }
}

//sets the sprites position
void Player::setSpritePos(int _mX, int _mY){

    setPos(_mX, _mY);

    for(auto &f: frames){

        f.setPosition( getX(), getY());
    }
}

//moves the sprites by Increment
void Player::moveSprites(int _mX, int _mY){

    for(auto &f: frames){

        f.move( _mX, _mY);
    }
}

//detects key input and changes the value of the facing integer
void Player::keyInput(){

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

    facing = none;
    }
}




/////////////////////////////////////////////////////////////////////////////////////////////////////////
//         this is the player loop, it takes care of all functions that belong to                    ////
//                      the player object and will be drawn in main                                  ////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
                            void Player::Draw(){                                                       //
                                                                                                       //
                                keyInput();                                                            //
                                movePlayer();                                                          //
                                win.draw(getNext());                                                   //
                            }                                                                          //
/////////////////////////////////////////////////////////////////////////////////////////////////////////




void Player::setPos(int _mX, int _mY){

    pX = _mX;
    pY = _mY;
}

//these return pX and pY player position integers
int Player::getX(){

        return pX;
}

int Player::getY(){

    return pY;
}

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

bool Player::getCollision(){

    return colliding;
}

void Player::setCollision(bool _c){

    colliding = _c;
}
