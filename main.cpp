#include <SFML\Graphics.hpp>
#include <Player.h>
#include <Arena.h>
#include <Game.h>

int main(){

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "BOMBER MAN");

    window.setFramerateLimit(12);


    Player pl(window);
    Arena arena(window);
    arena.makeArena(25, 25, 25, 25);

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

            //set back to smarter pointer mode

            //use a velocity to move the player, if moving causes a collision then reverse the vel a bit

            //this function must now be called in move, so collision data must be passed somehow

            break;
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
