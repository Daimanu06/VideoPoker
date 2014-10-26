#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <deque>
#include <memory>

namespace VideoPoker {

class Deck {
	friend class PrintDeck;

	public:
        Deck();

	public:
		void shuffle();
		void sort();
		void reset();
		/**
		 * @brief draw
		 * Extract the front card.
		 * After this function, the deck won't be full anymore until we reset() it.
         * @return the front card of the deck
		 */
        Card draw();

	private:
        std::deque< Card > m_cards;
};

} //!namespace

#endif // DECK_H
