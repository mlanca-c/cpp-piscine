/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:11:00 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/06/24 15:38:07 by mlancac          ###   ########.fr       */
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
	DEBUG( "<Point> constructor called" );
}

/* ************************************************************************** */
/* Operator Overload                                                          */
/* ************************************************************************** */

Point	Point::operator=( Point const& rhs ) {
	return ( Point( rhs ));
}

std::ostream&	operator<<( std::ostream& os, Point const& rhs ) {

	os << "Point( " << rhs.getX() << ", " << rhs.getY() << " )";
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

Fixed Point::area( Point const a, Point const b, Point const c) {

	Fixed	area;

	area = a.getX() * ( b.getY() - c.getY() );
	area = area + b.getX() * ( a.getY() - c.getY() );
	area = area + c.getX() * ( a.getY() - b.getY() );
	area = area.fabs();
	area = area / 2.0f;

	return ( area );
}
