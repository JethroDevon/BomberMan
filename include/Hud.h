
// ----------------------------------------
//                            | |          |
//   ▒▒▒▒▒▒▒▒▄▄▄▄▄▄▄▄▒▒▒▒▒▒   |=|      _|  |
//   ▒▒█▒▒▒▄██████████▄▒▒▒▒   | | (_) (_|  |
//   ▒█▐▒▒▒████████████▒▒▒▒                |
//   ▒▌▐▒▒██▄▀██████▀▄██▒▒▒   Hud class    |
//   ▐┼▐▒▒██▄▄▄▄██▄▄▄▄██▒▒▒   simply       |
//   ▐┼▐▒▒██████████████▒▒▒   overlays an  |
//   ▐▄▐████─▀▐▐▀█─█─▌▐██▄▒   image that   |
//   ▒▒█████──────────▐███▌   displays     |
//   ▒▒█▀▀██▄█─▄───▐─▄███▀▒   user data    |
//   ▒▒█▒▒███████▄██████▒▒▒   and options  |
//   ▒▒▒▒▒██████████████▒▒▒   and is drawn |
//   ▒▒▒▒▒█████████▐▌██▌▒▒▒   at the end   |
//   ▒▒▒▒▒▐▀▐▒▌▀█▀▒▐▒█▒▒▒▒▒   of the main  |
// game loop, it takes in data passed to   |
// it by the game class and contains logic |
// for the player to exit the game to the  |
// main GUI.                               |
// ----------------------------------------

#ifndef HUD_H
#define HUD_H


class Hud{

    //: public Sprites{

    public:
        Hud();
        virtual ~Hud();
    protected:
    private:
};

#endif // HUD_H
