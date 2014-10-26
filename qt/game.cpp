#include "game.h"
#include "hand.h"
#include "player.h"
#include "machine.h"

#include "printer.h"
#include <iostream>

namespace VideoPoker {

Game::Game() {
    //
}

Game::~Game() {
    //
}

void Game::play() {
    Player player(100);
    m_machine.bet(player.withdraw(50));

    phase1();
}

void Game::phase1() {
    std::cout << "First distribution\n";
    Hand hand = m_machine.distribuate();
    for(int i = 0; i < 5; i++)
        std::cout << hand.get_card(i).get_rank() << hand.get_card(i).get_suit() << ' ';
    std::cout << '\n';
}

} //!namespace
