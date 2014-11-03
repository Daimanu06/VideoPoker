#include "window.h"

namespace VideoPoker {
    namespace TUI {

        Window::Window(int h, int w, int y, int x) :
            win(newwin(h, w, y, x))
        {}

        void Window::Deleter::operator ()(WINDOW *win) const {
            delwin(win);
        }

        /*** Title window ***/
        Title::Title(int h, int w, int y, int x) :
            Window(h, w, y, x) {}

        GameState Title::update() {
            return GS_IDLE;
        }

        void Title::render() {
            mvwprintw(win.get(), 0, 0, "VideoPoker");
            wrefresh(win.get());
        }

        /*** Cards window ***/
        Cards::Cards(int h, int w, int y, int x) :
            Window(h, w, y, x)
        {
            //box(win.get(), 0, 0);
            wattron(win.get(), COLOR_PAIR(1));
            for(int i = 0; i < h; i++)
                mvwhline(win.get(), i, 0, ' ', COLS);
        }
        Cards::~Cards() {
            wattroff(win.get(), COLOR_PAIR(1));
        }

        GameState Cards::update() {
            return GS_IDLE;
        }

        void Cards::render() {
            //mvwprintw(win.get(), 0, 0, "+-----+");
            //TODO: create 5 Card in Cards
            wrefresh(win.get());
        }

        /*** Infos window ***/
        Infos::Infos(int h, int w, int y, int x) :
            Window(h, w, y, x) {}

        GameState Infos::update() {
            return GS_IDLE;
        }

        void Infos::render() {
            mvwprintw(win.get(), 0, 0, "Infos");
            wrefresh(win.get());
        }

        /*** Messages window ***/
        Messages::Messages(int h, int w, int y, int x) :
            Window(h, w, y, x) {}

        GameState Messages::update() {
            return GS_IDLE;
        }

        void Messages::render() {
            mvwprintw(win.get(), 0, 0, "Messages");
            wrefresh(win.get());
        }

        /*** Controls window ***/
        Controls::Controls(int h, int w, int y, int x) :
            Window(h, w, y, x) {}

        GameState Controls::update() {
            int ch = wgetch(win.get());
            if(ch == 'q' || ch == 'Q') {
                return GS_QUIT;
            }
            return GS_IDLE;
        }

        void Controls::render() {
            mvwprintw(win.get(), 0, 0, "q, Q - Quit the game    r, R - New round    <space> - Hold or discard a card    <Enter> - Get a new hand");
            wrefresh(win.get());
        }

    } //! namespace
} //! namespace
