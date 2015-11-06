
// -------------------------------------------------------------------
//     @|\@@                               _                          |
//    -  @@@@                             |_)                         |
//   /7   @@@@                            |    _        _  ._      _  |
//  /    @@@@@@                           |   (_) \/\/ (/_ |  (_) |_) |
//  \-' @@@@@@@@`-________________                                |   |
//   -@@@@@@@@@                /  \  dcau                             |
//   _____/    /_       ______/   |_____- The power up class Derives  |
//  /,________/  `-.___/,__________-----_)from the sprite class and   |
// contains functions to manage simple animations, logic to pass into |
// game class to power up players and detect collisions.              |
// -------------------------------------------------------------------
#ifndef POWERUP_H
#define POWERUP_H


class PowerUp
{
    public:
        PowerUp();
        ~PowerUp();

        int getPosX();
        int getPosY();

    private:

        int poX, poY, poH, poW;
};

#endif // POWERUP_H
