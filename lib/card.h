#ifndef CARD_H
#define CARD_H

#include <string>

namespace VideoPoker {

class Card {
	public:
		enum Rank {
			Ace,
			Two,
			Three,
			Four,
			Five,
			Six,
			Seven,
			Eight,
			Nine,
			Ten,
			Jack,
			Queen,
			King
		};
		enum Suit {
			Clubs,
			Hearts,
			Spades,
			Diamonds
		};

	public:
        Card(Rank, Suit);

        Card(Card&&) = default;
        Card& operator= (Card&&) = default;

        Card(const Card&) = delete;
        Card& operator= (const Card&) = delete;

    public:
        char get_rank() const;
        char get_suit() const;

	public:
		bool operator < (const Card&) const; //used to sort the deck

	private:
        Rank m_rank;
        Suit m_suit;

};

} //!namespace

#endif // CARD_H
