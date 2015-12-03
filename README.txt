					                   
				
					              ~~~ BOMBERMAN~~~         


A simple bomberman game with at least keyboarded multiplayer and a choice of several levels possibly of different sizes, I am using SFML version 2.0 with codeblocks, a guide to the installation of which is at the end of the readme:


                                      
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



				     Done:

can now load different levels up by changing path in main.

can create bombs dynamically.

collisions work but are bugged.

player faces direction when he mves that way also bugged.

all necissary animation functions are available in sprite.

all necisary collision functions are available in sprite, may include pointer to blocks/bombs/players and pickups but feel this is against modular style, may
put a comment box to isolate it out for future programs or create a template class for things like players blocks o rbombs etc.

main loop set up to run temporary code, will only be similar, intend to keep as much code out of main as possible.

created bomb in front of player, use facing enum in switch, collision block in front of player dissalows creating bomb overlapping block

created bomb timer: include time.h , get ticks, pickups will tweak bomb timers even freeze so lotsf of set and get functions

bomb collisions: player collides with bombs and players will collide with all bombs later on. 

bomb blast animation and collision: use blast loop, each bomb creates x amount of sub bombs with bomb handiling array in bomb, must destroy pointers and add to 
array dynamicaly, must use flag to kill player when bomb is of blast type boolean, this will also switch the animation loop images and detect by destruction function,
bomb collisions were not passed by pointer in the end, there was a flag function  that called to draw blast at position

debuged bounding boxes and movement: might have to change movement architecture as is buggy in movement and animation when player collides

block colliding with bomb blast: this destroys block and stops further creation of blasts in this direction, pass pointers through collision loop

mysterious walking animation bug solved, changing player facing variable half way through an animation loop causes a flag frame to be skipped

multiple keyboard players: add player loop so pl object is player array instead, add option to gui

bomb blasts killing players

colour for seperation of two players

bomb blasts colliding with bombs setting them off


~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

			TO-DO list:  

bug with keyboard, one keypress cancells another, look into threading

Image manager: a static image loader class can load all textures once and pass required textures into sprite constructor, this will stop loading an image each time
a new block is created at the beginning or a bomb is dynamically created.

players colliding with bombs but not if they have just laid one

hud, add minimum displayable stuff, use mouse hover to bring about options and pause in game

gui: use same hud button class, maybe start with splash and display loading messages

pickups: add a couple of pickups for proof of concept

polishing

no time -> networked players: set up udp server in gui, when connected hit go, use json library, also send server/client status messages, use ticks class for timouts



~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


					Code::Blocks SFML Installation Guide



Prerequisites:

1. Download and install Code::Blocks 
http://sourceforge.net/projects/codeblocks/files/Binaries/12.11/Windows/codeblocks-12.11mingw-setup.exe

2. Download and install cmake
http://www.cmake.org/files/v2.8/cmake-2.8.11.1-win32-x86.exe

3. Download and extract SFML source
http://www.sfml-dev.org/download/sfml/2.0/SFML-2.0-sources.zip

Building the Libs:	
4. Open a command prompt and change directory to the MinGW folder in the codeblocks folder.
"C:\Program Files (x86)\CodeBlocks\MinGW" on my system. Keep this CMD window open.

5. Run mingwvars.bat from command prompt.

6. Run cmake-gui from the command prompt.

7. In cmake-gui browse to where the SFML-2.0-sources folder was extracted and set the subdirectory SFML-2.0
to where the source is. ex: C:/Users/Sean/Downloads/SFML-2.0-sources/SFML-2.0

8. Set where to build binaries, I use a build directory in the source tree.
ex: C:/Users/Sean/Downloads/SFML-2.0-sources/build
You do not need to create the directory before hand, cmake will ask if you want it to create it.

9. Click configure, cmake will ask what generator to use, select "CodeBlocks - MinGW Makefiles"
with the "Use default native compilers radio button selected. Click finish.

10. After it is done configuring click generate. This will generate makefiles for release shared (DLL) build.
Keep cmake open, we will repeat these steps for release static, debug shared, and debug static.

11. Open Code::blocks, select open existing project. Browse to the directory where files 
were generated, SFML-2.0-sources/build in step 8. 

12. Select SFML.cbp, make sure "all" is set as build target and click build.

13. If build was successful, and it should be, change build target to install and click build 
it should install to C:\Program Files (x86)\SFML (you may need to elevate privileges to install here)

14. If you want the configurations (release static, debug shared, and debug static) go back to cmake window
change release to debug and/or uncheck build shared libs. Ideally you should have 4 configurations 
built but it isn't necessary.

Setting up Code::Blocks:

15. After all the libs are built and installed, close the SFML project and select File>New>Project.
In the "New from template" window scroll down and select SFML project.

16. In the project wizard name the project and click next.

17. The wizard will ask the location of SFML, set this to where SFML was installed 
("C:\Program Files (x86)\SFML" for me) and click next.

18. Check create "debug" configuration and click finish.

19. If all went well the project should be created. open the generated source file "main.cpp"
Don't run it, it wont compile it was written in SFML-1.6. Replace it with the code at the bottom 
of this page http://sfml-dev.org/tutorials/2.0/start-cb.php

20. Click build, it should compile without issue. Click run, it should produce an error about the SFML
DLLs being missing. Copy them from "C:\Program Files (x86)\SFML\bin" to <project folder>\bin\Debug|Release











