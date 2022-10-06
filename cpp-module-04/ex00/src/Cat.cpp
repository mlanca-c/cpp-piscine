/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:25:48 by mlancac           #+#    #+#             */
/*   Updated: 2022/09/27 08:27:38 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

Cat::Cat( void ) : Animal( "Cat" ) {
	DEBUG( "<Cat> default constructor called" );
}

Cat::~Cat( void ) { DEBUG( "<Cat> destructor called" ); }

Cat::Cat( Cat const& src ) : Animal( src ) {

	*this = src;
	DEBUG( "<Cat> copy constructor called" );
}

/* ************************************************************************** */
/* Operator Overload                                                          */
/* ************************************************************************** */

Cat&	Cat::operator=( Cat const& rhs ) {
	
	Animal::operator=( rhs );
	return ( *this );
}

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

void	Cat::makeSound( void ) const {
	std::cout << "<" << this->_type << ">: * meow *" << std::endl;
}
