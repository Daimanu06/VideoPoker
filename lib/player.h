#ifndef PLAYER_H
#define PLAYER_H

#include "money.h"

namespace VideoPoker {

class Player {
	friend class PrintPlayer;

	private:
		Kitty m_kitty;

	public:
		Player(Kitty = 0);

	public:
		/**
		 * @brief bet Withdraw money from Kitty and return it as a bet.
		 *
		 * Calling this function with no amount ( amount = 0 ) returns an empty bet value.
		 * If we can't withdraw a such amount from the kitty, we empty the kitty and return its content.
		 * @return the successfully withdrawn money frome the kitty.
		 */
		Bet withdraw(Money amount);
};

} //!namespace

#endif // PLAYER_H
