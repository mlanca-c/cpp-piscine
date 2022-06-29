/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:11:00 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/06/25 14:03:53 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

Point::Point( void ) : _x( Fixed( 0 )), _y( Fixed( 0 )) {
	DEBUG( "<Point> default constructor called" );
}

Point::~Point( void ) {
	DEBUG( "<Point> destructor called" );
}

Point::Point( Point const& src ) : _x( src.getX() ), _y( src.getY() ){
	DEBUG( "<Point> copy constructor called" );
}

Point::Point( float const x, float const y ) :
	_x( Fixed( x )), _y( Fixed( y )) {
	DEBUG( "<Point> float constructor called" );
}

Point::Point( Fixed x, Fixed y ) {
	const_cast<Fixed&>(_x) = x;
	const_cast<Fixed&>(_y) = y;
	DEBUG( "<Point> fixed constructor called" );
}

/* ************************************************************************** */
/* Operator Overload                                                          */
/* ************************************************************************** */

Point	Point::operator=( Point const& rhs ) {

	const_cast<Fixed&>(_x) = rhs._x;
	const_cast<Fixed&>(_y) = rhs._y;
	return ( *this );
}

Point	Point::operator+( Point const& rhs ) const {
	return ( Point( this->_x + rhs._x, this->_y + rhs._y ));
}

Point	Point::operator-( Point const& rhs ) const {
	return ( Point( this->_x - rhs._x, this->_y - rhs._y ));
}

Fixed	Point::operator*( Point const& rhs ) const {
	return ( Fixed( this->_x * rhs._x + this->_y * rhs._y ));
}

std::ostream&	operator<<( std::ostream& os, Point const& rhs ) {

	os << "( " << rhs.getX() << ", " << rhs.getY() << " )";
	return ( os );
}

/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */

Fixed const&  Point::getX( void ) const { return ( this->_x ); }

Fixed const&  Point::getY( void ) const { return ( this->_y ); }

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

