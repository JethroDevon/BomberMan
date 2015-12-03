#include <SFML/Graphics.hpp>
#include <Player.h>
#include <Arena.h>
#include <Game.h>

int main(){

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "BOMBER MAN");

    //setting frame rate, appears to stay the same on different computers
    window.setFramerateLimit(12);

    //--ARENA AND SETUP FUNCTIONS MUST BE CREATED BEFORE PLAYER--
    Arena arena(window);
    arena.loadLevel("levels/normal.txt");
    arena.makeArena(25, 25);

    //creating player one and player two
    Player pl(window);
    Player pl2(window);

    //sets starting positions for two players and adds a coloured hue to tell them apart with
    pl.setPos(26,26);
    pl2.setPos(454, 454);
    pl.colorSprite(0,200,0);
    pl2.colorSprite(200,0,0);

    //points changes to arena to stored copy in player for checking against collisions
    pl.setArena(arena);
    pl2.setArena(arena);

    // run the program as long as the window is open
    while (window.isOpen()){

        //create an event object for main loop
        sf::Event event;

         // clear the window with black colour
        window.clear(sf::Color::Green);

        //draws the arena (background)
        arena.drawBlocks();

        //checks pl collisions against the arena and if there are any sets them to true, is called here for all players to
        //check and to take advantage of arenaCheck functions args
        pl.setCollide(pl.arenaCheck(pl, false));
        pl2.setCollide(pl2.arenaCheck(pl2, false));

        //checks players against their own bomb blasts and the opponents bomb blasts
        pl.collideBlast(pl.handler, pl);
        pl.collideBlast(pl2.handler, pl);
        pl2.collideBlast(pl.handler, pl2);
        pl2.collideBlast(pl2.handler, pl2);

        //checks un-ignited bombs against blasting ones, this will set them off
        pl.igniteBlast(pl.handler);
        pl.igniteBlast(pl2.handler);
        pl2.igniteBlast(pl.handler);
        pl2.igniteBlast(pl2.handler);

        //draw player sprites
        pl.Draw();
        pl2.Draw();

        //Key Input, presently bugged, needs to be in two separate threads maybe
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){

             pl.moveUp();
        }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){

             pl.moveDown();
        }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){

            pl.moveLeft();
        }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){

            pl.moveRight();
        }



        if (event.type == sf::Event::TextEntered) {

            char c = static_cast<char> (event.text.unicode);

            if (c == 'w'){

                pl2.moveUp();
            }else if (c == 's'){

                    pl2.moveDown();
            }else if (c == 'a'){

                    pl2.moveLeft();
            }else if (c == 'd'){

                pl2.moveRight();
            }
        }


        //this is seperate from the main block so player can walk and lay bombs
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){

            pl.layBomb();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)){

            pl2.layBomb();
        }

        // end the current frame
        window.display();

        //very basic temporary win lose conditions for debugging purposes
        if(pl.getDeath()){


            window.close();
            std::cout<< "Player One loses, Player Two wins"<<std::endl;
        }
        if(pl2.getDeath()){

            window.close();
            std::cout<< "Player Two loses, Player One wins" <<std::endl;
        }


         //check for events
        while (window.pollEvent(event)){

            //if close request, then close window
            if (event.type == sf::Event::Closed){

                window.close();
            }
        }
    }



    //garbage collecting here--I cannot find what it is thats not being collected on shut down!
    pl.garbage();
    pl2.garbage();
    arena.garbage();

    //end everything
    return 0;
}
