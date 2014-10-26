#ifndef MONEY_H
#define MONEY_H

namespace VideoPoker {

class Money {
	public:
		typedef long money_t;

	public:
		Money(money_t initial_amount = 0);

	public:
		void  deposite(const Money amount);
		Money withdraw(const Money amount);
		Money empty(); //withdraw all
		money_t amount() const;

	private:
		money_t m_amount;
};

typedef Money Bet;
typedef Money Kitty;

} //!namespace

#endif // MONEY_H
