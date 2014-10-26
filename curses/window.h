#ifndef WINDOW_H
#define WINDOW_H

#include <ncurses.h>
#include <memory>

namespace VideoPoker {
    namespace TUI {

        class Window {
            public:
                Window(int h, int w, int y, int x);
                virtual ~Window() = default;

            public:
                virtual void render() = 0;

                struct Deleter{
                        void operator() (WINDOW *) const;
                };

            public:
                std::unique_ptr<WINDOW, Deleter> win;
        };

        struct Title : public Window {
            Title(int h, int w, int y, int x);
            void render() override;
        };

        struct Cards : public Window {
            Cards(int h, int w, int y, int x);
            ~Cards();
            void render() override;
        };

        struct Card : public Window {
            Card(int h, int w, int y, int x);
            void render() override;
        };

        struct Messages : public Window {
            Messages(int h, int w, int y, int x);
            void render() override;
        };

        struct Infos : public Window {
            Infos(int h, int w, int y, int x);
            void render() override;
        };

        struct Controls : public Window {
            Controls(int h, int w, int y, int x);
            void render() override;
        };

    } //! namespace
} //! namespace

#endif // WINDOW_H
