/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:57:57 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/06/21 17:25:40 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

Weapon::Weapon( void ) : _type( "weapon" ) {
	DEBUG( "Weapon <" << this->getType() << "> default constructor called" );
}

Weapon::~Weapon( void ) {
	DEBUG( "Weapon <" << this->getType() << "> destructor called" );
}

Weapon::Weapon( std::string type ) : _type( type ) {
	DEBUG( "Weapon <" << this->getType() << "> constructor called" );
}

/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */

std::string const&	Weapon::getType( void ) const { return ( this->_type ); }

void		Weapon::setType( std::string type ) { this->_type = type; }
