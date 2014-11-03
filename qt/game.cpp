#include "game.h"
#include "machine.h"
#include "mainwindow.h"
#include <QApplication>

namespace VideoPoker {

class Game::Impl {
    public:
        Impl();
        ~Impl();

    public:
        void play();
        void update();
        void render();

    private:
        MainWindow *m_window; //View
        Machine m_machine; //Model
};

Game::Game() : pimpl(new Impl()) {}

Game::~Game() {}

void Game::play() {
    pimpl->play();
}

void Game::distribuate() {
}

/** Implementation **/
Game::Impl::Impl() :
    m_window(new MainWindow())
{}

Game::Impl::~Impl() {}

void Game::Impl::play() {
    m_window->show();
}

} //!namespace
