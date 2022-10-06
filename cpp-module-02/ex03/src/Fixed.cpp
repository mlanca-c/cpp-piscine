/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:35:44 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/24 13:05:46 by mlancac          ###   ########.fr       */
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

/* Comparison Operators */

bool	Fixed::operator<( Fixed const& rhs ) const {
	return ( this->_raw < rhs.getRawBits() );
}

bool	Fixed::operator>( Fixed const& rhs ) const {
	return ( rhs < *this );
}

bool	Fixed::operator<=( Fixed const& rhs ) const {
	return ( !( *this > rhs ));
}

bool	Fixed::operator>=( Fixed const& rhs ) const {
	return ( !( *this < rhs ));
}

bool	Fixed::operator==( Fixed const& rhs ) const {
	return ( this->_raw == rhs.getRawBits() );
}

bool	Fixed::operator!=( Fixed const& rhs ) const {
	return ( !( *this == rhs ));
}

/* Arithmetic Operators */

Fixed	Fixed::operator+( void ) const {
	return ( Fixed( this->toFloat() ));
}

Fixed	Fixed::operator-( void ) const {
	return ( Fixed( this->toFloat() * -1 ));
}

Fixed	Fixed::operator+( Fixed const& rhs ) const {
	return ( Fixed( this->toFloat() + rhs.toFloat() ));
}

Fixed	Fixed::operator-( Fixed const& rhs ) const {
	return ( Fixed( this->toFloat() - rhs.toFloat() ));
}

Fixed	Fixed::operator*( Fixed const& rhs ) const {
	return ( Fixed( this->toFloat() * rhs.toFloat() ));
}

Fixed	Fixed::operator/( Fixed const& rhs ) const {
	return ( Fixed( this->toFloat() / rhs.toFloat() ));
}

/* Increment and Decrement Operators */

Fixed	Fixed::operator++( int ) {

	Fixed	tmp( *this );
	
	++( *this );
	return ( tmp );
}

Fixed	Fixed::operator--( int ) {

	Fixed	tmp( *this );

	--( *this );
	return ( tmp );
}

Fixed&	Fixed::operator++( void ) {
	
	*this = *this + 1;
	return ( *this );
}

Fixed&	Fixed::operator--( void ) {

	*this = *this - 1;
	return ( *this );
}

/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */

int	Fixed::getRawBits( void ) const { return ( this->_raw ); }

void	Fixed::setRawBits( int const raw ) { this->_raw = raw; }

/* ************************************************************************** */
/* Other Functins                                                             */
/* ************************************************************************** */

int		Fixed::toInt( void ) const { return ( this->_raw >> this->_fBits ); }

float	Fixed::toFloat( void ) const {
	return ( this->_raw / ( float )( 1 << this->_fBits ));
}

Fixed	Fixed::fabs( void ) const {
	return ( this->toFloat() > 0 ? *this : -( *this ));
}

Fixed const&	Fixed::max( Fixed const& lhs, Fixed const& rhs ) {
	return ( lhs > rhs ? lhs : rhs );
}

Fixed const&	Fixed::min( Fixed const& lhs, Fixed const& rhs ) {
	return ( lhs > rhs ? rhs : lhs );
}

Fixed&	Fixed::max( Fixed& lhs, Fixed& rhs ) {
	return ( lhs > rhs ? lhs : rhs );
}

Fixed&	Fixed::min( Fixed& lhs, Fixed& rhs ) {
	return ( lhs > rhs ? rhs : lhs );
}
