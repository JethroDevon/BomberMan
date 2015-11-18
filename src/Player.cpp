#include "Player.h"

//initialise window object and set sprites to be a base class of player, this way
//Sprites functions can be used by player class, 4 and 6 represent the rows and columns of the amount of images in the sprite contact sheet
Player::Player(sf::RenderWindow &_window): win(_window), Sprites("player.png", 4, 6){

    //sets base classes idle frame
    idle = 6;

    //for now start pos will be set here
    setPos( 26, 26);

    //sets width and height of player
    setWH(20, 20);

    //default facing value draws players facing the right
    facing = right;

    //this sets the animation to draw the loop where the player is facing right
    //set sprite animation for walking left
    loopMode(newFace(), 18, 23);
}

Player::~Player(){
    //dtor
}

//detects key input and changes the value of the facing integer, then moves the player
//also manages key inputto create a bomb
void Player::keyInput(){


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){

        //up key is pressed: move character up
        facing = up;

         //set sprite animation for walking up
        loopMode(newFace(), 0, 6);

        //move sprite up incrementally
        movePos(getCollide(), 0, -6);

    }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){

        // left key is pressed: move character
        facing = down;

        //set sprite animation for walking down
        loopMode(newFace(), 6, 12);

        //move sprite down incrementally
        movePos(getCollide(), 0, 6);

    }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){

        // left key is pressed: move character
        facing = left;

         //set sprite animation for walking left
        loopMode(newFace(), 12, 18);

        //move sprite left incrementally
        movePos(getCollide(), -6, 0);

    }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){

        // left key is pressed: move character
        facing = right;

        //set sprite animation for walking left
        loopMode(newFace(), 18, 23);

        //move sprite left incrementally
        movePos(getCollide(), 6, 0);
    }

    //this is seperate from the main block so player can walk and lay bombs
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){

        //checks facing enum value to create a bomb in front of the player depending on
        //which way its facing
        switch(getFace()){

            case 1:

                 //creates a new bomb, an offset of -40 -40 would draw a bomb at the location of the player, plus or minus some would be in
                 //the area above or below
                handler.push_back(new Bomb(getPosX() -40, getPosY()-60, 5, 5));
                break;

            case 2:

                 //creates a new bomb, an offset of -40 -40 would draw a bomb at the location of the player, plus or minus some would be in
                 //the area above or below
                handler.push_back(new Bomb(getPosX() -40 , getPosY() -20 , 5, 5));
                break;

            case 3:

                 //creates a new bomb, an offset of -40 -40 would draw a bomb at the location of the player, plus or minus some would be in
                 //the area above or below
                handler.push_back(new Bomb(getPosX() -60 , getPosY() -40 , 5, 5));
                break;

             case 4:

                 //creates a new bomb, an offset of -40 -40 would draw a bomb at the location of the player, plus or minus some would be in
                 //the area above or below
                handler.push_back(new Bomb(getPosX() -20, getPosY() -40, 5, 5));
                break;
        }

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

