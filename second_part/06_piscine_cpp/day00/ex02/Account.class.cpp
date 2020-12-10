#include "Account.class.hpp"
#include <iostream>
#include <sys/time.h>

Account::Account() {}
Account::Account(int initial_deposit) : _accountIndex(Account::_nbAccounts),
	_amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->checkAmount() << ";created" << std::endl;
	Account::_nbAccounts += 1;
	Account::_totalAmount += initial_deposit;
	return ;
}

Account::~Account() {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->checkAmount() << ";closed" << std::endl;
	Account::_nbAccounts -= 1;
	Account::_totalAmount -= this->checkAmount();
}

void	Account::makeDeposit(int deposit) {
	this->_amount += deposit;
	this->_nbDeposits += 1;
	Account::_totalNbDeposits += 1;
	Account::_totalAmount += deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->checkAmount() - deposit << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal ) {
	if (withdrawal > this->checkAmount()) {
		Account::_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";";
		std::cout << "p_amount:" << this->checkAmount() << ";";
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals += 1;
	Account::_totalNbWithdrawals += 1;
	Account::_totalAmount -= withdrawal;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->checkAmount() + withdrawal << ";";
	std::cout << "withdrawal:" << withdrawal << ";";
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

int	Account::checkAmount() const {
	this->_checkAmountCalls += 1;
	return (this->_amount);
}

void	Account::displayStatus() const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
	return ;
}

int Account::getNbAccounts() {
	return (Account::_nbAccounts);
}

int Account::getTotalAmount() {
	return (Account::_totalAmount);
}

int Account::getNbDeposits() {
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals() {
	return (Account::_totalNbWithdrawals);
}

void	Account::_displayTimestamp() {
	struct timeval tp;
	gettimeofday(&tp, NULL);
	//long int ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
	std::cout << "[" << tp.tv_sec << "_" << tp.tv_usec << "] ";
}

void	Account::displayAccountsInfos() {
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts();
	std::cout << ";total:" << Account::getTotalAmount();
	std::cout << ";deposits:" << Account::getNbDeposits();
	std::cout << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}


int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;