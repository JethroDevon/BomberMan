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

    //set the player position to draw
    setPosXY(_mX, _mY);

    for(auto &f: frames){

        f.setPosition( getPosX(), getPosY());
    }
}

//moves the sprites by Increment
void Player::moveSprites(int _mX, int _mY){

   //set the player position to draw
    setPosXY(getPosX() + _mX, getPosY() + _mY);

    for(auto &f: frames){

        f.move( _mX, _mY);
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



//set X and Y position of player
void Player::setPosXY(int _mX, int _mY){

    pX = _mX;
    pY = _mY;
}

//these return pX and pY player position integers
int Player::getPosX(){

        return pX;
}

int Player::getPosY(){

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

//this function draws all the blocks on the screen
void Player::drawBombs(){

    //loops through the handler array that contains an array of bombs that belong to player
    for(auto f: handler){

        //draws image function referred to frame in sprites
        win.draw( f->bombFrame());
    }
}

