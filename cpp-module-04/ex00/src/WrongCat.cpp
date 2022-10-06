/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:25:48 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/30 16:41:07 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

WrongCat::WrongCat( void ) : WrongAnimal( "WrongCat" ) {
	DEBUG( "<WrongCat> default constructor called" );
}

WrongCat::~WrongCat( void ) { DEBUG( "<WrongCat> destructor called" ); }

WrongCat::WrongCat( WrongCat const& src ) {

	*this = src;
	DEBUG( "<WrongCat> copy constructor called" );
}

/* ************************************************************************** */
/* Operator Overload                                                          */
/* ************************************************************************** */

WrongCat&	WrongCat::operator=( WrongCat const& rhs ) {
	
	WrongAnimal::operator=( rhs );
	return ( *this );
}

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

void	WrongCat::makeSound( void ) const {
	std::cout << "<" << this->_type << ">: * miaaaaaaaaaau *" << std::endl;
}
