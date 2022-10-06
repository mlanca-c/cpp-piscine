/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:17:56 by mlancac           #+#    #+#             */
/*   Updated: 2022/09/27 09:26:48 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

Animal::Animal( void ) : _type( "Animal" ) {
	DEBUG( "Animal <" << this->_type << "> default constructor called" );
}

Animal::~Animal( void ) {

	DEBUG( "Animal <" << this->_type << "> destructor called" );
}	

Animal::Animal( Animal const& src ) {

	*this = src;
	DEBUG( "Animal <" << this->_type << "> copy constructor called" );
}

Animal::Animal( std::string type ) : _type( type ) {
	DEBUG( "Animal <" << this->_type << "> constructor called" );
}

/* ************************************************************************** */
/* Operator Overload                                                          */
/* ************************************************************************** */

Animal&	Animal::operator=( Animal const& rhs ) {

	this->_type = rhs._type;
	return ( *this );
}

std::ostream&	operator<<( std::ostream& os, Animal const& rhs ) {

	os << "Animal <" << rhs.getType() << ">";
	return ( os );
}

/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */

std::string	Animal::getType( void ) const { return ( this->_type ); }

void	Animal::setType( std::string type ) { this->_type = type; }

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

void	Animal::makeSound( void ) const {

	std::cout << "<" << this->_type << ">: * makes a weird animal sound *"
			  << std::endl;
}
