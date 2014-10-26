#include "deck.h"
#include <algorithm>
#include <random>

namespace VideoPoker {

Deck::Deck() {
	reset();
}

void Deck::shuffle() {
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(m_cards.begin(), m_cards.end(), g);
}

void Deck::sort() {
	std::sort(m_cards.begin(), m_cards.end());
}

void Deck::reset() {
	m_cards.clear();
    for(int rank = 0; rank < 13; rank++)
        for(int suit = 0; suit < 4; suit++)
            m_cards.emplace_back( Card(Card::Rank(rank), Card::Suit(suit)) );
}

Card Deck::draw() {
    auto card(std::move(m_cards.front()));
	m_cards.pop_front();
    return card;
}

} //!namespace
