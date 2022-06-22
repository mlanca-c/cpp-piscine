/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:35:44 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/22 17:25:07 by mlanca-c         ###   ########.fr       */
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

Fixed::Fixed ( int const i ) : _raw( i << this->_fBits ) {
	DEBUG( "<Fixed:"<< i << "> constructor called");
}

Fixed::Fixed ( float const f ) : _raw( roundf( f * ( 1 << this->_fBits ))) {
	DEBUG( "<Fixed:" << f << "> constructor called");
}

/* ************************************************************************** */
/* Operator Overload                                                          */
/* ************************************************************************** */

Fixed&	Fixed::operator=( Fixed const& rhs ) {
	DEBUG("<Fixed> operator= called");
	this->setRawBits( rhs.getRawBits() );
	return (*this);
}

std::ostream&	operator<<( std::ostream& os, Fixed const& rhs ) {
	os << rhs.toFloat();
	return ( os );
}

/* Comparison Operators */
bool	Fixed::operator<( Fixed const& rhs ) const;

bool	Fixed::operator>( Fixed const& rhs ) const;

bool	Fixed::operator<=( Fixed const& rhs ) const;

bool	Fixed::operator>=( Fixed const& rhs ) const;

bool	Fixed::operator==( Fixed const& rhs ) const;

bool	Fixed::operator!=( Fixed const& rhs ) const;

/* Arithmetic Operators */
Fixed	Fixed::operator+( void ) const;

Fixed	Fixed::operator-( void ) const;

Fixed	Fixed::operator+( Fixed const& rhs ) const;

Fixed	Fixed::operator-( Fixed const& rhs ) const;

Fixed	Fixed::operator*( Fixed const& rhs ) const;

Fixed	Fixed::operator/( Fixed const& rhs ) const;

/* Increment/Decrement Operators */
Fixed	Fixed::operator++( void );

Fixed	Fixed::operator--( void );

Fixed&	Fixed::operator++( int );

Fixed&	Fixed::operator--( int );

/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */

int	Fixed::getRawBits( void ) const { return (this->_raw); }

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

Fixed const&	Fixed::max( Fixed const& lhs, Fixed const& rhs ) const;

Fixed&	Fixed::max( Fixed& lhs, Fixed& rhs ) const;

Fixed const&	Fixed::min( Fixed const& lhs, Fixed const& rhs ) const;

Fixed&	Fixed::min( Fixed& lhs, Fixed& rhs ) const;
