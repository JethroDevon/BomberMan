					                     BOMBERMAN

Done:

I intend to make a bomberman game with at least keyboarded multiplayer and a choice of several levels possibly of different sizes.

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

					             TO-DO list:

bomb blast animation and collision: use blast loop, each bomb creates x amount of sub bombs with bomb handiling array in bomb, must destroy pointers and add to 
array dynamicaly, must use flag to kill player when bomb is of blast type boolean, this will also switch the animation loop images and detect by destruction function,
bomb collisions must be passed by pointer 

block colliding with bomb blast: this destroys block and stops further creation of blasts in this direction, pass pointers through collision loop

debug bounding boxes and movement: might have to change movement architecture as is buggy in movement and animation when player collides

Image manager: a static image loader class can load all textures once and pass required textures into sprite constructor, this will stop loading an image each time
a new block is created at the beginning or a bomb is dynamically created.

multiple keyboard players: add player loop so pl object is player array instead, add option to gui, make modular for...

hud, add minimum displayable stuff, use mouse hover to bring about options and pause in game

gui: use same hud button class, maybe start with splash and display loading messages

pickups: add a couple of pickups for proof of concept

polishing: make not look shit

networked players: set up udp server in gui, when connected hit go, use json library, also send server/client status messages, use ticks class for timouts

polishing

