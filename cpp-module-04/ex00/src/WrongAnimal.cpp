/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:17:56 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/30 16:39:03 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

WrongAnimal::WrongAnimal( void ) : _type( "WrongAnimal" ) {
	DEBUG( "<WrongAnimal> default constructor called" );
}

WrongAnimal::~WrongAnimal( void ) { DEBUG( "<WrongAnimal> destructor called" ); }

WrongAnimal::WrongAnimal( WrongAnimal const& src ) {

	*this = src;
	DEBUG( "<WrongAnimal> copy constructor called" );
}

WrongAnimal::WrongAnimal( std::string type ) : _type( type ) {
	DEBUG( "<" << this->_type << "> constructor called" );
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


