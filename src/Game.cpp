#include "Game.h"

Game::Game(int _n):n(_n){

}

//templated collisions function, checks if the first object is colliding with the second
template<typename A, typename B>
int collisions(A a, B b){

    //for(auto & i: a){

     //   std::cout<<": " << a << std::endl;
    //}

    return a + b;
}
