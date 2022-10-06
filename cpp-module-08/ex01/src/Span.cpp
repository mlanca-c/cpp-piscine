/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:39:38 by mlancac           #+#    #+#             */
/*   Updated: 2022/07/07 12:56:46 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

Span::Span( void ) { DEBUG( "<Span> default constructor called" ); }

Span::~Span( void ) { DEBUG( "<Span> destructor called" ); }

Span::Span( Span const& src ) : _size( src._size ), _vect( src._vect ) {
	DEBUG( "<Span> copy constructor called" );
}

Span::Span( unsigned int N ) : _size( N ) {
	DEBUG( "<Span> constructor called" );
}

/* ************************************************************************** */
/* Operator Overload                                                          */
/* ************************************************************************** */

Span&	Span::operator=( Span const& rhs ) {

	this->_size = rhs._size;
	this->_vect = rhs._vect;
	return ( *this );
}

/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */

unsigned int	Span::size( void ) const { return ( this->_size ); }

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

void	Span::addNumber( int n ) throw( std::exception ) {

	if ( this->_size > this->_vect.size() )
		this->_vect.push_back( n );
	else
		throw( std::exception() );
}

int	Span::shortestSpan( void ) const throw( std::exception ) {

	if ( this->_vect.size() < 2 )
		throw( std::exception() );

	std::vector<int>	vect( this->_vect );
	std::sort( vect.begin(), vect.end() );
	std::adjacent_difference( vect.begin(), vect.end(), vect.begin() );
	return ( *std::min_element( vect.begin() + 1, vect.end() ));
}

int	Span::longestSpan( void ) const throw( std::exception ) {

	if ( this->_vect.size() < 2 )
		throw( std::exception() );

	return ( *std::max_element( this->_vect.begin(), this->_vect.end() )
		- *std::min_element( this->_vect.begin(), this->_vect.end() ));
}

void	Span::addNumbers(std::vector<int>::iterator it1,
		std::vector<int>::iterator it2 ) throw( std::exception ) {

	try {
		for ( std::vector<int>::iterator i = it1; i < it2; i++ )
			addNumber( rand() );
	}
	catch ( std::exception& e ) { throw ( e ); }
}
