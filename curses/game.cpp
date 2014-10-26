#include "game.h"
#include "window.h"
#include <ncurses.h>
#include <sstream>
#include <vector>

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
        void validate_interface();
        bool run = true;

    private:
        std::vector<std::unique_ptr<TUI::Window>> wins;
        Machine m_machine;
};

Game::Game() : pimpl(new Impl()) {}
Game::~Game() {}

void Game::play() {
    pimpl->play();
}

/** Implementation **/
Game::Impl::Impl() {
    using namespace TUI;

    initscr();

    validate_interface();

    start_color();
    init_pair(1, COLOR_WHITE, COLOR_GREEN);

    noecho();
    curs_set(0); //hide cursor
    //h w y x
    wins.emplace_back(new Title   ( 1,         COLS, 0,         0 ));
    wins.emplace_back(new Cards   ( LINES - 9, COLS, 1,         0));
    wins.emplace_back(new Infos   ( 6,         COLS, LINES - 8, 0));
    wins.emplace_back(new Messages( 1,         COLS, LINES - 2, 0));
    wins.emplace_back(new Controls( 1,         COLS, LINES - 1, 0));
    keypad(wins.back()->win.get(), true); //actually, back is the control window.

}

Game::Impl::~Impl() {
    curs_set(1); //show cursor
    endwin();
}

void Game::Impl::validate_interface() {
    if( !has_colors() ) {
        endwin();
        throw(std::string("The terminal must be able to show colors."));
    }

    /** Screen dimensions **/
    unsigned int scrw, scrh;
    getmaxyx(stdscr, scrh, scrw);

    unsigned int WIN_WIDTH = 20, WIN_HEIGHT = 15;
    if(scrw < WIN_WIDTH || scrh < WIN_HEIGHT) {
        endwin();
        std::ostringstream oss;
        oss << "The terminal is too small.\n";
        oss << "Its size must be at least ";
        oss << WIN_WIDTH << "\303\227" << WIN_HEIGHT;
        oss << " (currently " << scrw << "\303\227" << scrh << ")",
        throw(oss.str());
    }
}

void Game::Impl::play() {
    while(run) {
        render();
        update();
    }
}

void Game::Impl::update() {
    int ch = wgetch(wins.back()->win.get());
    if(ch == 'q' || ch == 'Q') {
        run = false;
    }
}

void Game::Impl::render() {
    for(auto& win : wins)
        win->render();
}

} //! namespace
