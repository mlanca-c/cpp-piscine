/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:30:54 by mlancac           #+#    #+#             */
/*   Updated: 2022/09/27 08:28:23 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

Dog::Dog( void ) : Animal( "Dog" ) {
	DEBUG( "<Dog> default constructor called" );
}

Dog::~Dog( void ) { DEBUG( "<Dog> destructor called" ); }

Dog::Dog( Dog const& src ) : Animal( src ) {

	*this = src;
	DEBUG( "<Dog> copy constructor called" );
}

/* ************************************************************************** */
/* Operator Overload                                                          */
/* ************************************************************************** */

Dog&	Dog::operator=( Dog const& rhs ) {
	
	Animal::operator=( rhs );
	return ( *this );
}

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

void	Dog::makeSound( void ) const {
	std::cout << "<" << this->_type << ">: * woof *" << std::endl;
}
