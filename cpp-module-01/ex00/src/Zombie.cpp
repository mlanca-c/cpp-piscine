/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:41:06 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/06/26 14:34:07 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

Zombie::Zombie( void ) { DEBUG( "<Zombie> default constructor called" ); }

Zombie::~Zombie( void ) {
	DEBUG( "<" << this->getName() << "> destructor called" );
}

Zombie::Zombie( std::string name ) : _name( name ) {
	DEBUG( "<" << this->_name << "> constructor called" );
}

/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */

std::string	Zombie::getName( void ) const { return ( this->_name ); }

void	Zombie::setName( std::string name ) { this->_name = name; }

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

void	Zombie::anounce( void ) {
	std::cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
