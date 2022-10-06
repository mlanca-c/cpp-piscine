/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:17:56 by mlancac           #+#    #+#             */
/*   Updated: 2022/09/27 09:33:53 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

AAnimal::AAnimal( void ) : _type( "AAnimal" ), _brain( new Brain() ) {
	DEBUG( "AAnimal <" << this->_type << "> default constructor called" );
}

AAnimal::~AAnimal( void ) {

	delete this->_brain;
	DEBUG( "AAnimal <" << this->_type << "> destructor called" );
}

AAnimal::AAnimal( AAnimal const& src ) {

	*this = src;
	DEBUG( "AAnimal <" << this->_type << "> copy constructor called" );
}

AAnimal::AAnimal( std::string type ) : _type( type ), _brain( new Brain() ) {
	DEBUG( "AAnimal <" << this->_type << "> constructor called" );
}

/* ************************************************************************** */
/* Operator Overload                                                          */
/* ************************************************************************** */

AAnimal&	AAnimal::operator=( AAnimal const& rhs ) {

	this->_type = rhs._type;
	if ( this->_brain ) delete this->_brain;
	this->_brain = rhs._brain->clone();
	return ( *this );
}

std::ostream&	operator<<( std::ostream& os, AAnimal const& rhs ) {

	os << "Animal <" << rhs.getType() << "> " << *( rhs.getBrain() );
	return ( os );
}

/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */

std::string	AAnimal::getType( void ) const { return ( this->_type ); }

void	AAnimal::setType( std::string type ) { this->_type = type; }

Brain*	AAnimal::getBrain( void ) const { return ( this->_brain ); }

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

void	AAnimal::makeSound( void ) const {

	std::cout << "<" << this->_type << ">: * makes a weird animal sound *";
	std::cout << std::endl;
}
