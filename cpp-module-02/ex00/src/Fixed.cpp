/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:19:35 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/06/29 11:18:14 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fBits = 8;

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

Fixed::Fixed( void ) : _raw( 0 ) {
	DEBUG( "<Fixed> default constructor called");
}

Fixed::Fixed( Fixed const& src ) {
	DEBUG( "<Fixed> copy constructor called" );
	*this = src;
}

Fixed::~Fixed( void ) { DEBUG( "<Fixed> destructor called"); }

/* ************************************************************************** */
/* Operator Overload                                                          */
/* ************************************************************************** */

Fixed&	Fixed::operator=( Fixed const& rhs ) {

	DEBUG("<Fixed> operator= called");
	this->setRawBits( rhs.getRawBits() );
	return (*this);
}

/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */

int	Fixed::getRawBits( void ) const { return (this->_raw); }

void	Fixed::setRawBits( int const raw ) { this->_raw = raw; }

/* ************************************************************************** */
/* Other Functins                                                             */
/* ************************************************************************** */

