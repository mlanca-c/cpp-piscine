/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:34:12 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/06/28 15:52:31 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

HumanA::~HumanA( void ) {
	DEBUG( "HumanA <" << this->getName() << "> destructor called" );
}

HumanA::HumanA( Weapon& weapon ): _name( "HumanA" ), _weapon( weapon ) {
	DEBUG( "HumanA <" << this->getName() << "> constructor called" );
}

HumanA::HumanA( std::string name, Weapon& weapon ):
	_name( name ), _weapon( weapon ) {
	DEBUG( "HumanA <" << this->getName() << "> constructor called" );
}

/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */

std::string const&	HumanA::getName( void ) const { return ( this->_name ); }

Weapon const&	HumanA::getWeapon( void ) const { return ( this->_weapon ); }

void	HumanA::setName( std::string name ) { this->_name = name; }

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

void	HumanA::attack( void ) const {
	std::cout << this->getName() << " attacks with their "
			  << this->getWeapon().getType() << std::endl;
}
