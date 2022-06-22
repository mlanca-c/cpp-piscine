/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:35:44 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/22 14:07:21 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

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

