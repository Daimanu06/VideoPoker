#include "printer.h"
#include "deck.h"
#include "hand.h"
#include "machine.h"
#include "player.h"
#include <iostream>
#include <memory>

namespace VideoPoker {

void PrintDeck::operator () (const Deck &deck, std::ostream &os) const {
    os << std::string(30, '*') << std::endl;
    for(auto& card : deck.m_cards)
        os << card.get_rank() << card.get_suit() << '\n';
    os << std::string(30, '*') << std::endl;
}

void PrintHand::operator ()(const Hand &hand, std::ostream& os) {
    os << std::string(30, '*') << std::endl;
	os << "** My hand **\n";
    for(std::size_t i = 0; i < hand.m_cards.size(); i++)
        os << hand.m_cards.at(i).get_rank() << hand.m_cards.at(i).get_suit() << ' ' << (hand.m_held.at(i) ? "held" : "discarded") << '\n';
    os << std::string(30, '*') << std::endl;
}


void PrintMachine::operator()(const Machine &machine, std::ostream &os) {
    os << std::string(30, '*') << std::endl;
	os << "** Machine current state **\n";
	PrintDeck()(machine.m_deck, os);
	os << "bet: " << machine.m_bet.amount() << '\n';
    os << std::string(30, '*') << std::endl;
}


void PrintPlayer::operator ()(const Player &player, std::ostream &os) {
    os << std::string(30, '*') << std::endl;
	os << player.m_kitty.amount() << '\n';
    os << std::string(30, '*') << std::endl;
}

} //!namespace
