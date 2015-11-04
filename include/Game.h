// ---------------------------------------------------------------
//           _..---...,""-._     ,/}/)          _                 |
//        .''        ,      ``..'(/-<          / \                |
//       /   _      {      )         \         | _  _. .___   _   |
//      ;   _ `.     `.   <         a(         \_/ (_| | | | (/_  |
//    ,'   ( \  )      `.  \ __.._ .: y                           |
//   (  <\_-) )'-.____...\  `._   //-'         This Class Manages |
//    `. `-' /-._)))      `-._)))              logic for the      |
//      `...'                                  game, it contains  |
// a function to detect collisions for the bomb player and        |                                                              |
//   Arena class, updates HUD class data and manages              |
// game states for the GUI class to communicate with.             |
// ---------------------------------------------------------------
#ifndef GAME_H
#define GAME_H


class Game
{
    public:
        Game();

        bool collisions();();

    private:
};

#endif // GAME_H
