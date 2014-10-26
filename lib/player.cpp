#include "player.h"
#include <algorithm>

namespace VideoPoker {

Player::Player(Kitty kitty) :
	m_kitty{kitty}
{}

Bet Player::withdraw(Money amount) {
	return Bet(m_kitty.withdraw(amount));
}

} //!namespace
