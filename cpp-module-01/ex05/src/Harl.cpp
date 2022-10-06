/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:04:49 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/29 11:00:59 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

Harl::Harl( void ) {

	this->_f[0] = &Harl::debug;
	this->_f[1] = &Harl::info;
	this->_f[2] = &Harl::warning;
	this->_f[3] = &Harl::error;
	this->_level[0] = "DEBUG";
	this->_level[1] = "INFO";
	this->_level[2] = "WARNING";
	this->_level[3] = "ERROR";

	DEBUG( "<Harl> default constructor called" );
}

Harl::~Harl( void ) { DEBUG( "<Harl> destructor called" ); }

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

void	Harl::complain( std::string level ) {

	for ( int i = 0; i < 4; i++ )
		if ( this->_level[i] == level ) ( this->*_f[i] )();
}

void	Harl::debug( void ) {

	std::cout << "[ DEBUG ]: I love having extra bacon for my"
			  << "7XL-double-cheese-triple-pickle-specialketchup burger. "
			  << "I really do!" << std::endl;
}

void	Harl::info( void ) {

	std::cout << "[ INFO ]: "
			  << "I cannot believe adding extra bacon costs more money. "
			  << "You didn’t put enough bacon in my burger! "
			  << "If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning( void ) {

	std::cout << "[ WARNING ]: "
			  << "I think I deserve to have some extra bacon for free. "
			  << "I’ve been coming for years whereas you started working here "
			  << "since last month." << std::endl;
}

void	Harl::error( void ) {

	std::cout << "[ ERROR ]: This is unacceptable! "
			  << "I want to speak to the manager now." << std::endl;
}
