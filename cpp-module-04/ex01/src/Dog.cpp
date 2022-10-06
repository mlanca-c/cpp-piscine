/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:30:54 by mlancac           #+#    #+#             */
/*   Updated: 2022/09/27 09:18:08 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

Dog::Dog( void ) : Animal( "Dog" ), _brain( new Brain() ) {
	DEBUG( "<Dog> default constructor called" );
}

Dog::~Dog( void ) {
	
	delete this->_brain;
	DEBUG( "<Dog> destructor called" );
}

Dog::Dog( Dog const& src ) : Animal( src ), _brain( new Brain() ) {

	*this = src;
	DEBUG( "<Dog> copy constructor called" );
}

/* ************************************************************************** */
/* Operator Overload                                                          */
/* ************************************************************************** */

Dog&	Dog::operator=( Dog const& rhs ) {
	
	Animal::operator=( rhs );
	if ( this->_brain ) delete this->_brain;
	this->_brain = rhs._brain->clone();
	return ( *this );
}


std::ostream&	operator<<( std::ostream& os, Dog const& rhs ) {

	os << rhs.getType() << " " << *( rhs.getBrain() );
	return ( os );
}

/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */

Brain*	Dog::getBrain( void ) const { return ( this->_brain ); }

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

void	Dog::makeSound( void ) const {
	std::cout << "<" << this->_type << ">: * woof *" << std::endl;
}
