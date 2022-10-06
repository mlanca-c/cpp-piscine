/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:04:49 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/29 11:09:30 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

Harl::Harl( void ) {

	this->_f[0] = &Harl::debug;
	this->_level[0] = "DEBUG";
	this->_f[1] = &Harl::info;
	this->_level[1] = "INFO";
	this->_f[2] = &Harl::warning;
	this->_level[2] = "WARNING";
	this->_f[3] = &Harl::error;
	this->_level[3] = "ERROR";

	DEBUG( "<Harl> default constructor called" );
}

Harl::~Harl( void ) { DEBUG( "<Harl> destructor called" ); }

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

void	Harl::filter( std::string level ) {

	int	a;

	for ( a = 0; a < 5; a++ ) {
		if ( this->_level[a] == level ) break ;
	}

	switch ( a ) {

		case 0:
			(this->*_f[0])();

		case 1:
			(this->*_f[1])();

		case 2:
			(this->*_f[2])();

		case 3:
			(this->*_f[3])();
			break ;

		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}

}

void	Harl::complain( std::string level ) {

	for ( int i = 0; i < 4; i++ ) {
		if ( this->_level[i] == level )
			(this->*_f[i])();
	}
}

void	Harl::debug( void ) {

	std::cout << "[ DEBUG ]: ";
	std::cout << "I love having extra bacon for my";
	std::cout << "7XL-double-cheese-triple-pickle-specialketchup burger. ";
	std::cout << "I really do!" << std::endl;
}

void	Harl::info( void ) {

	std::cout << "[ INFO ]: ";
	std::cout << "I cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn’t put enough bacon in my burger! ";
	std::cout << "If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning( void ) {

	std::cout << "[ WARNING ]: ";
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I’ve been coming for years whereas you started working here ";
	std::cout << "since last month." << std::endl;
}

void	Harl::error( void ) {

	std::cout << "[ ERROR ]: ";
	std::cout << "This is unacceptable! ";
	std::cout << "I want to speak to the manager now." << std::endl;
}
