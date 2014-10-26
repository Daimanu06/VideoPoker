#include "money.h"
#include <algorithm>

namespace VideoPoker {

Money::Money(money_t initial_amount) :
	m_amount(initial_amount)
{
}

void Money::deposite(const Money amount) {
	m_amount += amount.amount();
}

Money Money::withdraw(const Money amount) {
	money_t to_withdraw = std::min(amount.amount(), m_amount);
	m_amount -= to_withdraw;
	return to_withdraw;
}

Money Money::empty() {
	money_t to_withdraw = m_amount;
	m_amount = 0;
	return to_withdraw;
}

Money::money_t Money::amount() const {
	return m_amount;
}

} //!namespace
