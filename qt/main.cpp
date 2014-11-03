#include "game.h"
#include <iostream>
#include <QApplication>

int main(int argc, char **argv) {
    try {
        QApplication app(argc, argv);
        VideoPoker::Game game;
        game.play();
        app.exec();
    } catch(const std::string &what) {
        std::cerr << "Fatal error: " << what << std::endl;
    } catch(const char *what) {
        std::cerr << "Fatal error: " << what << std::endl;
    } catch(...) {
        std::cerr << "Fatal error!" << std::endl;
    }

    return 0;
}
