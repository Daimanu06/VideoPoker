#ifndef HAND_H
#define HAND_H

#include "card.h"
#include <array>
#include <memory>

namespace VideoPoker {

class Hand {
	friend class PrintHand;

	public:
        typedef std::array<Card, 5> cards_t;
		typedef std::array<bool, 5> held_t;
        typedef unsigned int index_t;

	public:
        Hand(cards_t);

	public:
        void hold(index_t);
        void discard(index_t);
        const Card& get_card(index_t);

	private:
        cards_t m_cards;
		held_t m_held;
};

} //!namespace

#endif // HAND_H
