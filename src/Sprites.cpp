#include "Sprites.h"

//constructor
Sprites::Sprites(std::string _path): path( _path){

 //if image is successfully loaded
 if(setImage()){

    //sets sprites in sprite sheet
    setSprite();
    std::cout << "Image @" << path << " loaded." << std::endl;
 }else{

    std::cout << "Image @   " << path << " failed." << std::endl;
 }

}

//overloaded constructor for contact sheets with multiple frames on them
Sprites::Sprites(std::string _path, int _rows, int _cols): path( _path){

rows = _rows;
cols = _cols;

 //if image is found go ahead and initialise member variables
 if(setImage()){

    std::cout << "Image @" << path << " loaded." <<std::endl;

    //set a starting frame, total frames and call frame array building function
    frame = 0;
    startFrame = frame;
    total_frames = (rows * cols);

    //breaks down image into frames in vector of sprites
    addFrames();
 }else{

    std::cout << "Image @   " << path << " failed." << std::endl;
 }

}

//destructor
Sprites::~Sprites(){

    delete sp_copy;
}


void Sprites::setSprite(){

            //total_frames = (rows * cols) - 1;
            tex.create(cntSheet.getSize().x, cntSheet.getSize().y);
            tex.update(cntSheet);
            sprite.setTexture(tex);
}

//adds frames to the array called frames by pushing back sub images
void Sprites::addFrames(){

            //create texture and update the image from image file
            tex.create(cntSheet.getSize().x, cntSheet.getSize().y);
            tex.update(cntSheet);

            //work out the size of the subframes if contact image is
            //set up to cut images in this way
            int width = (1 * cntSheet.getSize().x)/cols;
            int height = (1 * cntSheet.getSize().y)/rows;

            //loop for each row and column of texture image creating sub images for animation
            for(int c = 0; c < rows ; c++){
                    for(int r = 0; r < cols ; r++){

                        //create temporary sprite object
                        sf::Sprite tempSprite;

                        //set whole texture to smaller sprite
                        tempSprite.setTexture(tex);

                        //set that sprites texture to be a sub image of main image in order to create a frame
                        tempSprite.setTextureRect(sf::IntRect( r*width, c*height, width, height));

                        //push that back onto array.
                        frames.push_back(tempSprite);
                    }
            }
            //return debug data
             std::cout << "Added  " << frames.size() << " frames." << std::endl;
}

//gets the next sprite in the frame
sf::Sprite Sprites::getNext(){


    //std::cout << "displaying sprite from path- " <<  path << " and frame: "<< frame<< "." << std::endl;
    if(frame < total_frames-1){

        frame++;
        return frames[frame];
    }else{

        frame = startFrame;
        return frames[frame];
    }
}

//this function will effect the nextFrame function, if a loop is set then
//the only animation nextFrame will show is between two integers called startF
//and stopF also manages loop mode, if takes in bad variables turns loop mode off again
void Sprites::loopMode(int sa, int so){

    //if new arguments would cause a crash set loop back to false
    if((sa < 0 || sa > total_frames )|| (so < 1 || so > total_frames)){

        total_frames = (rows*cols)-1;
        startFrame = 0;

    }else{

        frame = sa;
        total_frames = so;
        startFrame = sa;
    }


}

//this overloaded version of above only changes direction
//if true is in the first argument
void Sprites::loopMode(bool b, int sa, int so){

    if(b){
        //if new arguments would cause a crash set loop back to false
        if((sa < 0 || sa > total_frames )|| (so < 1 || so > total_frames)){

            total_frames = (rows*cols)-1;
            startFrame = 0;

        }else{

            frame = sa;
            total_frames = so;
            startFrame = sa;
        }
    }
}

//sets sprite to show next without calling it
void Sprites::nextFrame(){


        if(frame < total_frames){

            frame++;

        }else{

            frame = startFrame;
        }
}

//moves all the sprites draw positions
void Sprites::movePos(int _x, int _y){

    //loops through each sprite
    for(auto f: frames){

        f.setPosition(_x, _y);
    }

}

//sets frame to frame selected to be the idle frames
void Sprites::idleFrame(){

    frame = idle;
    loopMode(idle, idle+3);
}

//sets frame to frame selected to be the idle frame
sf::Sprite Sprites::showFrame(){

    return frames[frame];
}

bool Sprites::setImage(){

    if (cntSheet.loadFromFile(path)){

        return true;
    }else{

        return false;
    }

}
