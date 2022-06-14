/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sottomayor <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:09:24 by Sottomayo         #+#    #+#             */
/*   Updated: 2022/04/28 17:29:57 by Sottomayo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) : _amount(initial_deposit) {

	this->_accountIndex = Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
		      << ";amount:" << this->_amount
		      << ";created" << std::endl;
}

Account::Account( void ) {
	Account::_nbAccounts++;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_amount = 0;
}

Account::~Account( void ) {
	Account::_nbAccounts--;
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
			  << ";amount:" << this->_amount
		      << ";closed" << std::endl;
}

/* ************************************************************************** */
/* Getters                                                                    */
/* ************************************************************************** */

int	Account::getNbAccounts( void ) { return (Account::_nbAccounts); } 

int	Account::getTotalAmount( void ) { return (Account::_totalAmount); } 

int	Account::getNbDeposits( void ) { return (Account::_totalNbDeposits); } 

int	Account::getNbWithdrawals( void ) { return (Account::_totalNbWithdrawals); }

/* ************************************************************************** */
/* Member Methods                                                             */
/* ************************************************************************** */

void	Account::displayAccountsInfos( void ) {
	Account::_displayTimestamp();
	std::cout << " accounts:" << Account::getNbAccounts()
		      << ";total:" << Account::getTotalAmount()
		      << ";deposits:" << Account::getNbDeposits()
		      << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit ) {
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
		      << ";p_amount:" << this->_amount
		      << ";deposit:" << deposit;
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
	std::cout << ";amount:" << this->_amount
			  << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
		      << ";p_amount:" << this->_amount;
	if (this->_amount >= withdrawal) {
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		std::cout << ";withdrawal:" << withdrawal
				  << ";amount:" << this->_amount
				  << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}
	std::cout << ";withdrawal:refused" << std::endl;
	return (false);
}

int		Account::checkAmount( void ) const {
	Account::_displayTimestamp();
	return (this->_amount);
}

void	Account::displayStatus( void ) const {
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
		      << ";amount:" << this->_amount
		      << ";deposits:" << this->_nbDeposits
		      << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void ) {
    char			buf[20];
	struct std::tm	*localT;
	std::time_t		time;

	if (DEBUG) {
		std::cout << "[19920104_091532]";
		return ;
	} 
	time = std::time(NULL);
    localT = std::localtime(&time);
    std::strftime(buf, 20, "[%Y%m%d_%H%M%S] ", localT);
    std::cout << buf;
}
