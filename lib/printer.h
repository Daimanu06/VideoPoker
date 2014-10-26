#ifndef PRINTER_H
#define PRINTER_H

#include <iostream>

namespace VideoPoker {

class Deck;
class PrintDeck {
    public:
        void operator () (const Deck&, std::ostream& = std::cout) const;
};

class Hand;
class PrintHand {
	public:
        void operator () (const Hand&, std::ostream& = std::cout);
};

class Machine;
class PrintMachine {
	public:
        void operator () (const Machine&, std::ostream& = std::cout);
};

class Player;
class PrintPlayer {
	public:
        void operator () (const Player&, std::ostream& = std::cout);
};

} //!namespace

#endif // PRINTER_H
