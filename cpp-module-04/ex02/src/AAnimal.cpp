/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:17:56 by mlancac           #+#    #+#             */
/*   Updated: 2022/07/01 13:16:46 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

AAnimal::AAnimal( void ) : _type( "AAnimal" ) {
	DEBUG( "<AAnimal> default constructor called" );
}

AAnimal::~AAnimal( void ) { DEBUG( "<AAnimal> destructor called" ); }

AAnimal::AAnimal( AAnimal const& src ) {

	*this = src;
	DEBUG( "<AAnimal> copy constructor called" );
}

AAnimal::AAnimal( std::string type ) : _type( type ) {
	DEBUG( "<" << this->_type << "> constructor called" );
}

/* ************************************************************************** */
/* Operator Overload                                                          */
/* ************************************************************************** */

AAnimal&	AAnimal::operator=( AAnimal const& rhs ) {

	this->_type = rhs._type;
	return ( *this );
}

std::ostream&	operator<<( std::ostream& os, AAnimal const& rhs ) {

	std::cout << "<AAnimal> " << rhs.getType();
	return ( os );
}

/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */

std::string	AAnimal::getType( void ) const { return ( this->_type ); }

void	AAnimal::setType( std::string type ) { this->_type = type; }

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

void	AAnimal::makeSound( void ) const {

	std::cout << "<" << this->_type << ">: * makes a weird animal sound *";
	std::cout << std::endl;
}

