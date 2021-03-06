#include "game.h"
#include <iostream>

int main(int argc, char **argv) {
    try {
        setlocale(LC_ALL,"");
        VideoPoker::Game game;
        game.play();
    } catch(const std::string &what) {
        std::cerr << "Fatal error: " << what << std::endl;
    } catch(const char *what) {
        std::cerr << "Fatal error: " << what << std::endl;
    } catch(...) {
        std::cerr << "Fatal error!" << std::endl;
    }

    return 0;
}
