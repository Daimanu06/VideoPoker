#ifndef GAME_H
#define GAME_H

#include "machine.h"
#include <memory>

namespace VideoPoker {

/**
 * @class Game
 *
 * Controller class.
 * Manages an user interface (View) and the data (Model).
 */
class Game {
    public:
        Game();
        ~Game();

    public:
       void play();

    private:
       void bet();
       void distribuate();
       void choose_cards();

    private:
       class Impl;
       std::unique_ptr<Impl> pimpl;
};

} //!namespace

#endif // GAME_H
