/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:17:56 by mlancac           #+#    #+#             */
/*   Updated: 2022/09/27 08:34:59 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

WrongAnimal::WrongAnimal( void ) : _type( "WrongAnimal" ) {
	DEBUG( "WrongAnimal <" << this->_type << "> default constructor called" );
}

WrongAnimal::~WrongAnimal( void ) {
	DEBUG( "WrongAnimal <" << this->_type << "> destructor called" );
}

WrongAnimal::WrongAnimal( WrongAnimal const& src ) {

	*this = src;
	DEBUG( "WrongAnimal <" << this->_type << "> copy constructor called" );
}

WrongAnimal::WrongAnimal( std::string type ) : _type( type ) {
	DEBUG( "WrongAnimal <" << this->_type << "> constructor called" );
}

/* ************************************************************************** */
/* Operator Overload                                                          */
/* ************************************************************************** */

WrongAnimal&	WrongAnimal::operator=( WrongAnimal const& rhs ) {

	this->_type = rhs._type;
	return ( *this );
}

std::ostream&	operator<<( std::ostream& os, WrongAnimal const& rhs ) {

	std::cout << "<WrongAnimal> " << rhs.getType();
	return ( os );
}

/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */

std::string	WrongAnimal::getType( void ) const { return ( this->_type ); }

void	WrongAnimal::setType( std::string type ) { this->_type = type; }

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

void	WrongAnimal::makeSound( void ) const {

	std::cout << "<" << this->_type << ">: * makes a weird animal sound *";
	std::cout << std::endl;
}


