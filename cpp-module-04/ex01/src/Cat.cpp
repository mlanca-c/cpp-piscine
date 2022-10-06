/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:25:48 by mlancac           #+#    #+#             */
/*   Updated: 2022/09/27 09:18:49 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

Cat::Cat( void ) : Animal( "Cat" ), _brain( new Brain() ) {
	DEBUG( "<Cat> default constructor called" );
}

Cat::~Cat( void ) {

	delete this->_brain;
	DEBUG( "<Cat> destructor called" );
}

Cat::Cat( Cat const& src ) : Animal( src ), _brain( new Brain() ) {

	*this = src;
	DEBUG( "<Cat> copy constructor called" );
}

/* ************************************************************************** */
/* Operator Overload                                                          */
/* ************************************************************************** */

Cat&	Cat::operator=( Cat const& rhs ) {
	
	Animal::operator=( rhs );
	if ( this->_brain ) delete this->_brain;
	this->_brain = rhs._brain->clone();
	return ( *this );
}

std::ostream&	operator<<( std::ostream& os, Cat const& rhs ) {

	os << rhs.getType() << " " << *( rhs.getBrain() );
	return ( os );
}

/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */

Brain*	Cat::getBrain( void ) const { return ( this->_brain ); }

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

void	Cat::makeSound( void ) const {
	std::cout << "<" << this->_type << ">: * meow *" << std::endl;
}
