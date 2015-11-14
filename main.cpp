#include <SFML\Graphics.hpp>
#include <Player.h>
#include <Arena.h>
#include <Game.h>

int main(){

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "BOMBER MAN");

    //setting frame rate, might change this to a function that will regulate framerate accross devoces
    window.setFramerateLimit(12);

    //temp initialisers for testing
    Player pl(window);
    Arena arena(window);
    arena.loadLevel("levels/normal.txt");
    arena.makeArena(25, 25);

    // run the program as long as the window is open
    while (window.isOpen()){

        //create an event object
        sf::Event event;

         //check for events
        while (window.pollEvent(event)){

            //if close request, then close window
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }


        // clear the window with black colour
        window.clear(sf::Color::Green);

        //draws the arena (background)
        arena.drawBlocks();

        for(auto *b: arena.handler){

           //check to see if player is colliding with any block objects
           if(pl.collission(b)){

                pl.setCollide(true);
                break;
           }else{

                pl.setCollide(false);
           }
        }

        //draw player sprites
        pl.Draw();

        // end the current frame
        window.display();
    }

    //garbage collecting here?
    return 0;
}
