/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:35:44 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/22 16:58:18 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

Fixed::Fixed( void ) : _raw( 0 ) {
	DEBUG( "Fixed <" << this->toFloat() << "> default constructor called" );
}

Fixed::~Fixed( void ) {
	DEBUG( "Fixed <" << this->toFloat() << "> destructor called" );
}

Fixed::Fixed( Fixed const& src ) {

	*this = src;
	DEBUG( "Fixed <" << this->toFloat() << "> copy constructor called" );
}

Fixed::Fixed ( int const i ) : _raw( i << this->_fBits ) {
	DEBUG( "Fixed <" << this->toInt() << "> constructor called" );
}

Fixed::Fixed ( float const f ) : _raw( roundf( f * ( 1 << this->_fBits ))) {
	DEBUG( "Fixed <" << this->toFloat() << "> constructor called" );
}

/* ************************************************************************** */
/* Operator Overload                                                          */
/* ************************************************************************** */

Fixed&	Fixed::operator=( Fixed const& rhs ) {

	this->setRawBits( rhs.getRawBits() );
	return ( *this );
}

std::ostream&	operator<<( std::ostream& os, Fixed const& rhs ) {

	os << rhs.toFloat();
	return ( os );
}

/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */

int	Fixed::getRawBits( void ) const { return ( this->_raw ); }

void	Fixed::setRawBits( int const raw ) { this->_raw = raw; }

/* ************************************************************************** */
/* Other Functins                                                             */
/* ************************************************************************** */

int		Fixed::toInt( void ) const {
	return ( this->_raw >> this->_fBits );
}

float	Fixed::toFloat( void ) const {
	return ( this->_raw / ( float )( 1 << this->_fBits ));
}
