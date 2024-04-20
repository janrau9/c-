/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janraub <janraub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 08:56:46 by janraub           #+#    #+#             */
/*   Updated: 2024/04/20 08:58:29 by janraub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


void Account::_displayTimestamp( void ) {
    std::time_t now;
    std::tm* timeinfo;
    char buffer[80];

    std::time(&now);
    timeinfo = std::localtime(&now);

    std::strftime(buffer, 80, "[%Y%m%d_%H%M%S] ", timeinfo);
    std::cout << buffer;
    
}

Account::Account( int initial_deposit ) : _accountIndex( Account::_nbAccounts++ ), _amount( initial_deposit ), _nbDeposits( 0 ), _nbWithdrawals( 0 ) {
    Account::_totalAmount += initial_deposit;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account( void ) {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

int Account::getNbAccounts( void ) {
    return Account::_nbAccounts;
}

int Account::getTotalAmount( void ) {
    return Account::_totalAmount;
}

int Account::getNbDeposits( void ) {
    return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals( void ) {
    return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}
    
void Account::makeDeposit( int deposit )
{
    int p_amount = _amount;
    if (deposit == 0)
    {
        std::cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount << ";deposit:" << deposit << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
        return;
    }
    this->_amount += deposit;
    this->_nbDeposits++;
    this->_totalNbDeposits++;
    this->_totalAmount += deposit;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount << ";deposit:" << deposit << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool    Account::makeWithdrawal( int withdrawal )
{
    int p_amount = this->_amount;
    if (this->_amount < withdrawal)
    {
        _displayTimestamp();
        std::cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount << ";withdrawal:refused" << std::endl;
        return (false);
    }
    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
    this->_totalNbWithdrawals++;
    this->_totalAmount -= withdrawal;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount << ";withdrawal:" << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return (true);
}

void    Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}