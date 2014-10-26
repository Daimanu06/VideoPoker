#include "hand.h"

namespace VideoPoker {

Hand::Hand(cards_t cards) :
    m_cards(std::move(cards)),
    m_held{true, true, true, true, true}
{}

void Hand::hold(index_t i) {
	m_held[i] = true;
}

void Hand::discard(index_t i) {
	m_held[i] = false;
}

const Card& Hand::get_card(index_t i) {
    return m_cards.at(i);
}

} //!namespace
