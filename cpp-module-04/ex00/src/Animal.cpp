/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:03:47 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/28 15:23:21 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

Animal::Animal( void ) : _type( "Animal" ) {
	DEBUG( "<Animal> default constructor called" );
}

Animal::~Animal( void ) { DEBUG( "<Animal> destructor called" ); }

Animal::Animal( Animal const& src ) {

	*this = src;
	DEBUG( "<Animal> copy constructor called" );
}

Animal::Animal( std::string type ) : _type( type ) {
	DEBUG( "<Animal> constructor called" );
}

/* ************************************************************************** */
/* Operator Overload                                                          */
/* ************************************************************************** */

Animal&	Animal::operator=( Animal const& rhs ) {
	
	this->_type = rhs._type;
	return ( *this );
}

std::ostream&	operator<<( std::ostream& os, Animal const& rhs ) {

	os << "Animal <" << rhs.getType() << ">";
	return ( os );
}

/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */

std::string	Animal::getType( void ) const { return ( this->_type ); }

void	Animal::setType( std::string type ) { this->_type = type; }

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

void	Animal::makeSound( void ) const {

	std::cout << "<" << this->_type << ">: ";
	std::cout << "makes a weird animal sound" << std::endl;
}
