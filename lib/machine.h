#ifndef MACHINE_H
#define MACHINE_H

#include "deck.h"
#include "money.h"

namespace VideoPoker {

    class Gain;
    class Hand;

    class Machine {
        friend class PrintMachine;

        public:
            Machine();

        public:
            /**
             * @brief bet Place a bet in the machine.
             * Doesn't check if the money was withdrawn from an account.
             */
            void bet(Bet);
            /**
             * @brief distribuate Distribuate 5 cards in a Hand from the front of the deck.
             * @return a Hand containing 5 cards.
             */
            Hand distribuate();
            Money collect_gains();

        private:
            Gain determine_gains();

        private:
            Deck m_deck;
            Bet m_bet;
    };

} //!namespace

#endif // MACHINE_H
