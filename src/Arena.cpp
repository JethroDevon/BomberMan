//this class deals with the blocks, backgrounds and player collisions in the bomber man arena
#include "Arena.h"

Arena::Arena(sf::RenderWindow &_window): win(_window){


}

Arena::~Arena(){

    //calls destructor on each object in vector
    handler.clear();
}

//this should make the blocks in the arena, its a cumbersome and ugly  bit of code
//however I want to be able to handle more unusual data later on with the possibility of
//a level generator or level logic of some kind
void Arena::makeArena(int block_width, int block_height){

    //total number of blocks that the level will contain
    int block_total = level.length();

    //this block will iterate through the string 'level' and return the present char
    int present_block = 0;

    //this will be the xposition to draw the block, it will multiply the block_width and
    //keep track of the x position to draw the next block, it will be reset by \n char
    int xGrid = 0;

    //this will multiply by block height, it will track the position to draw the blocks in their y positions
    //it will be multiplied by the \n char
    int yGrid = 0;

    //string type will manage the kind of block that must be drawn each iteration of the while loop
    char type;

    //loops for each char in string level until the end, the position of each string char will
    //determine the position the co responding block will be on the map
    while(present_block < block_total){

       type = level[present_block++];

        //draw a block if it exists
        if(type == '0' || type == '1'){

            //add block to array in this position, char is converted into either 1 or zero, the minus 48 is to remove ascii encoding
            //that may not be set up in preferences, got to fix this ugly way later on
            handler.push_back(new Block( ((int)type)-48 , xGrid * block_width, yGrid * block_height, block_width, block_height));

        //else if a three chances of being a destructible block or a solid block
        }else if(type == '3'){

           //seeds the next random number based on the time function
           srand (present_block+time(0));

           //creates a random number from one to ten, the + 1 is to avoid returning 0
           int temp = rand()%15;

           //chance of not initialising a block at all
           if(temp > 3 && temp < 10){

                //push back the randomly chosen solid or destructible block
                handler.push_back(new Block(1 , xGrid * block_width, yGrid * block_height, block_width, block_height));
           }else if(temp <= 3){

                //push back the randomly chosen solid or destructible block
                handler.push_back(new Block(0 , xGrid * block_width, yGrid * block_height, block_width, block_height));
           }
        }

        //increment grid by one each time a block in row yGrid is drawn
        xGrid++;

        //if new line is encountered
        if(type == '\n'){

            //rows are incremented
            yGrid++;

            //cols are reset
            xGrid = 0;
        }
    }
}

//this function draws all the blocks on the screen
void Arena::drawBlocks(){

    for(auto f: handler){

        win.draw( f->returnBlock(f->getType()));
    }
}

//returns console message if level loaded successfully or not
void Arena::loadLevel(std::string level_path){

    //default flag to return is set to true, an error will set flag to true
    bool loaded = false;

    //if the while loop loops more than two hundred times the while loop will be broken and
    //loaded will be set to false
    int loopCount;

    //loads text file
    std::string line;
	std::ifstream infile;
	infile.open(level_path);

	//checks state of file before level is made
    loaded = infile.good();

	//loop until stream returns end of file
	while(!infile.eof() && loaded){

        std::getline(infile, line);
        level += line + "\n";
        loopCount++;

        if(loopCount < 200 ){

            loaded = false;
        }
	}

    //closes stream
    infile.close();

    //outputs a console message as to whether the level loaded, if it did, the console draws the level
    //1 for success 0 for failure
	std::cout<< "LEVEL " << level_path << " LOADED CODE: " << loaded << "\n\n" << level << std::endl;
}
