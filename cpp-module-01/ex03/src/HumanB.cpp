/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:52:27 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/06/28 15:47:49 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

HumanB::HumanB( void ) : _name( "HumanB" ) {
	DEBUG( "HumanB <" << this->getName() << "> default constructor called" );
}

HumanB::~HumanB( void ) {
	DEBUG( "HumanB <" << this->getName() << "> destructor called" );
}

HumanB::HumanB( std::string name ) : _name( name ) {
	DEBUG( "HumanB <" << this->getName() << "> constructor called" );
}

/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */

std::string const&	HumanB::getName( void ) const { return ( this->_name ); }

Weapon const*	HumanB::getWeapon( void ) const { return ( this->_weapon ); }

void	HumanB::setName( std::string name ) { this->_name = name; }

void	HumanB::setWeapon( Weapon& weapon ) { this->_weapon = &weapon; }

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

void	HumanB::attack( void ) const {
	std::cout << this->getName() << " attacks with their "
			  << this->getWeapon()->getType() << std::endl;
}
