#include "machine.h"
#include "hand.h"
#include <functional>

namespace VideoPoker {

Machine::Machine() :
	m_bet{0}
{
	m_deck.shuffle();
}

void Machine::bet(Bet bet) {
	m_bet.deposite(bet);
}

Hand Machine::distribuate() {
    //TODO: what if there are not 5 cards left in the deck?
    return (
        Hand({
            m_deck.draw(),
            m_deck.draw(),
            m_deck.draw(),
            m_deck.draw(),
            m_deck.draw()
        }));
}

} //!namespace
