#include <SFML/Graphics.hpp>
#include <Player.h>
#include <Arena.h>
#include <Game.h>

int main(){

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "BOMBER MAN");

    //setting frame rate, might change this to a function that will regulate framerate accross devoces
    window.setFramerateLimit(12);

    //--ARENA AND SETUP FUNCTIONS MUST BE CREATED BEFORE PLAYER--
    Arena arena(window);
    arena.loadLevel("levels/normal.txt");
    arena.makeArena(25, 25);

    //temp initialisers for testinger
    Player pl(window);

    //points changes to arena to stored copy in player for checking against collisions
    pl.setArena(arena);

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

        //checks pl collisions against the arena and if there are any sets them to true, is called here for all players to
        //check and to take advantage of arenaCheck functions args
        pl.setCollide(pl.arenaCheck(pl, false));  //<--SETTING THIS TO TRUE IS INTERESTING



        //draw player sprites
        pl.Draw();

        // end the current frame
        window.display();
    }

    //garbage collecting here?
    return 0;
}
