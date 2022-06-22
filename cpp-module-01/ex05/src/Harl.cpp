/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:04:49 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/22 12:54:06 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

Harl::Harl( void ) { DEBUG( "<Harl> default constructor called" ); }

Harl::~Harl( void ) { DEBUG( "<Harl> destructor called" ); }

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

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
