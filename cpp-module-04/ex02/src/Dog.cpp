/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:30:54 by mlancac           #+#    #+#             */
/*   Updated: 2022/07/01 13:17:11 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

Dog::Dog( void ) : AAnimal( "Dog" ) {

	this->_brain = new Brain();
	DEBUG( "<Dog> default constructor called" );
}

Dog::~Dog( void ) {

	delete this->_brain;
	DEBUG( "<Dog> destructor called" );
}

Dog::Dog( Dog const& src ) {

	*this = src;
	DEBUG( "<Dog> copy constructor called" );
}

/* ************************************************************************** */
/* Operator Overload                                                          */
/* ************************************************************************** */

Dog&	Dog::operator=( Dog const& rhs ) {
	
	AAnimal::operator=( rhs );
	return ( *this );
}

std::ostream&	operator<<( std::ostream& os, Dog const& rhs ) {

	os << "<Dog> " << *( rhs.getBrain() );
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
	std::cout << "<" << this->_type << ">: * wuuuuuuuuuuuf *" << std::endl;
}
