/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:25:48 by mlancac           #+#    #+#             */
/*   Updated: 2022/09/27 09:35:21 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

Cat::Cat( void ) : AAnimal( "Cat" ) {
	DEBUG( "<Cat> default constructor called" );
}

Cat::~Cat( void ) { DEBUG( "<Cat> destructor called" ); }

Cat::Cat( Cat const& src ) : AAnimal( src ) {

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
/* Other Functions                                                            */
/* ************************************************************************** */

void	Cat::makeSound( void ) const {
	std::cout << "<" << this->_type << ">: * meow *" << std::endl;
}
