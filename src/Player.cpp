#include "Player.h"
#include <algorithm>

//initialise window object and set sprites to be a base class of player, this way
//Sprites functions can be used by player class, 4 and 6 represent the rows and columns of the amount of images in the sprite contact sheet
Player::Player(sf::RenderWindow &_window): win(_window), Sprites("player.png", 4, 6){

    //sets base classes idle frame
    idle = 6;

    //for now start pos will be set here
    setPos( 26, 26);

    //sets width and height of player
    setWH(18, 18);

    //default facing value draws players facing the right
    facing = right;

    //this sets the animation to draw the loop where the player is facing right
    //set sprite animation for walking left
    loopMode(newFace(), 18, 23);

    //default this must be off
    blastFlag = false;
}

Player::~Player(){

   //on the destruction of player the pointer to the arena
   delete arenareference;
}

//detects key input and changes the value of the facing integer, then moves the player
//also manages key input to create a bomb
void Player::keyInput(){


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){

         //up key is pressed: move character up
        facing = up;

         //set sprite animation for walking up
        loopMode(newFace(), 0, 6);

        //move sprite up incrementally
        movePos(getCollide(), 0, -4);



    }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){

         // left key is pressed: move character
        facing = down;

        //set sprite animation for walking down
        loopMode(newFace(), 6, 12);

        //move sprite down incrementally
        movePos(getCollide(), 0, 4);


    }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){


        // left key is pressed: move character
        facing = left;

         //set sprite animation for walking left
        loopMode(newFace(), 12, 18);

        //move sprite left incrementally
        movePos(getCollide(), -4, 0);

    }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){

        // left key is pressed: move character
        facing = right;

        //set sprite animation for walking left
        loopMode(newFace(), 18, 23);

        //move sprite left incrementally
        movePos(getCollide(), 4, 0);

    }


    //this is seperate from the main block so player can walk and lay bombs
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){

         //dont listen to key press if half a second has not passed
         if(getTicks(0.5)){

            //checks facing enum value to create a bomb in front of the player depending on
            //which way its facing
            switch(getFace()){

                case 1:

                    handler.push_back(new Bomb(getPosX() - getWidth()/3, getPosY() - getHeight() - 2 , 5, 5));
                    break;

                case 2:

                    handler.push_back(new Bomb(getPosX() - getWidth()/3, getPosY() + getHeight() - 2, 5, 5));
                    break;

                case 3:

                    handler.push_back(new Bomb(getPosX() - 20, getPosY() - (getHeight()/3), 5, 5));
                    break;

                 case 4:

                    handler.push_back(new Bomb(getPosX() + 10, getPosY() -( getHeight()/3), 5, 5));
                    break;

            }

            //if the newly created bomb is colliding with a block delete it
            if(arenaCheck(*handler.back(), false)){

                //destroy the object at the back of the list by calling its destructor
                handler.back()->destroy();

                //remove the pointer at the back of handler
                handler.pop_back();

                //and create one directly where the player is
                handler.push_back(new Bomb(getPosX() - getWidth()/4, getPosY(), 5, 5));
            }
        }
    }
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////
//         this is the player loop, it takes care of all functions that belong to                    ////
//                      the player object and will be drawn in main                                  ////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
                            void Player::Draw(){

                                doBlast();
                                drawBombs();
                                keyInput();
                                win.draw(getNext());
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
        return false;
    }else{

        return true;
    }
}

//this function draws all the blocks on the screen
void Player::drawBombs(){

    //loops through the handler array that contains an array of bombs that belong to player
    //loops through pointer types so as to be able to delete the actual pointer in the vector also
    for(auto sprt: handler){

        //draws image function referred to frame in sprites
        win.draw( sprt->bombFrame());

        //this function will assign the iterator to be the size of x amount of *bomb pointers
        auto it = std::remove_if( handler.begin(), handler.end(), [this](Bomb *bomb){

            //if it is an exploded bomb call the function that will create the blasts
            if(bomb->getUsed() && !bomb->getBlast()){

                //flags the bomb creator to create a blast in first arg and stores where to do it at x Y in next two args
                initBlast( true, bomb->getPosX(), bomb->getPosY(), bomb->getFlame());
            }

            return bomb->getUsed();
        });


            //need to also call destructor on whatever just stopped getting pointed to
             handler.erase(it, handler.end());
    }
}

//the following function will create the 'bomb.flame' amount of bombs in each direction but stop when colliding with a block
//the reference to the collision will destroy the block if it is of type
void Player::drawBlast(){

    //each for loop creates bombs in each of the four directions....
    for(int x = 0; x < getFlame(); x++){

        handler.push_back(new Bomb(getBlastX() + (x * 25), getBlastY()));

            if(arenaCheck(*handler.back(), true)){

                break;
            }
    }

    for(int x = 0; x < getFlame(); x++){

         handler.push_back(new Bomb(getBlastX() - (x * 25), getBlastY()));

            if(arenaCheck(*handler.back(), true)){

                break;
            }
    }
     for(int x = 0; x < getFlame(); x++){

        handler.push_back(new Bomb(getBlastX(), getBlastY() + (x * 25)));

            if(arenaCheck(*handler.back(), true)){

                break;
            }
    }

    for(int x = 0; x < getFlame(); x++){

         handler.push_back(new Bomb(getBlastX(), getBlastY()  - (x * 25)));

            if(arenaCheck(*handler.back(), true)){

                break;
            }
    }


}

void Player::doBlast(){

    if(blastFlag){

        drawBlast();
        blastFlag = false;
    }
}

int Player::getFlame(){

    return flame;
}

int Player::getBlastX(){

    return blastX;
}

int Player::getBlastY(){

    return blastY;
}

void Player::initBlast(bool _flag, int _x, int _y, int _f){

    blastFlag = true;
    blastX = _x;
    blastY = _y;
    flame = _f;
}

//this function allows collision logic with the arena for the player
//and bombs alike, if set to true will destroy block it is colliding with
bool Player::arenaCheck(Sprites _sp, bool kill){

    bool collided = false;


        for(auto b: arenareference->handler){

            //check to see if _sp is colliding with any block objects
            if(_sp.collission(b)){

                //if this is true then setMarked sets block object to be removed later.
                if(kill && b-> getType()){

                    b->setMarked(true);
                }

                //return true if there's a collision
                collided = true;
            }
        }


    return collided;
}

//this function sets a pointer to the arena class for operations that require
//checking and changing the arena class
void Player::setArena(Arena &arena){

    arenareference = &arena;
}


