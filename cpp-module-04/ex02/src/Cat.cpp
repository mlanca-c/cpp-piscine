/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:25:48 by mlancac           #+#    #+#             */
/*   Updated: 2022/07/01 13:17:05 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

Cat::Cat( void ) : AAnimal( "Cat" ) {

	this->_brain = new Brain();
	DEBUG( "<Cat> default constructor called" );
}

Cat::~Cat( void ) {

	delete this->_brain;
	DEBUG( "<Cat> destructor called" );
}

Cat::Cat( Cat const& src ) {

	*this = src;
	DEBUG( "<Cat> copy constructor called" );
}

/* ************************************************************************** */
/* Operator Overload                                                          */
/* ************************************************************************** */

Cat&	Cat::operator=( Cat const& rhs ) {
	
	AAnimal::operator=( rhs );
	return ( *this );
}

std::ostream&	operator<<( std::ostream& os, Cat const& rhs ) {

	os << "<Cat> " << *( rhs.getBrain() );
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
	std::cout << "<" << this->_type << ">: * miaaaaaaaaaau *" << std::endl;
}
