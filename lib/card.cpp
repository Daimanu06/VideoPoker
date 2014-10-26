#include "card.h"
#include <array>

namespace VideoPoker {

Card::Card(Rank rank, Suit suit) :
	m_rank(rank), m_suit(suit)
{}

char Card::get_rank() const {
    static char tt[] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
    return tt[m_rank];
}

char Card::get_suit() const {
    static char tr[] = {'C','H','S','D'};
	return tr[m_suit];
}

bool Card::operator <(const Card &other) const {
    if(m_suit == other.get_suit())
        return (m_rank < other.get_rank());
    return (m_suit < other.get_suit());
}

} //!namespace
