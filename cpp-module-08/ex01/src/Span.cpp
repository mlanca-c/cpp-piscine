/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:21:53 by mlancac           #+#    #+#             */
/*   Updated: 2022/10/07 15:07:09 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

Span::Span( void ) : _size( 0 ) {
	DEBUG( "<Span> default constructor called" );
}

Span::~Span( void ) { DEBUG( "<Span> destructor called" ); }

Span::Span( Span const& src ) : _size( src._size ), _vector( src._vector ) {
	DEBUG( "<Span> copy constructor called" );
}

Span::Span( unsigned int size ) : _size( size ) {
	DEBUG( "<Span> constructor called" );
}

/* ************************************************************************** */
/* Operator Overload                                                          */
/* ************************************************************************** */

Span&	Span::operator=( Span const& rhs ) {
	
	this->_size = rhs._size;
	this->_vector = rhs._vector;
	return ( *this );
}

int const&	Span::operator[]( unsigned int i ) const {

	if ( i >= this->_vector.size() )
		throw ( Span::IndexOutOfBoundsException() );
	return ( this->_vector[i] );
}

std::ostream&	operator<<( std::ostream& os, Span const& rhs ) {

	os << "span: ";
	for ( unsigned i = 0; i < rhs.getSize(); i++ )
		os << rhs[i] << ( i == rhs.getSize() - 1 ? "" : ", " );
	return ( os );
}

/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */

unsigned int	Span::getSize( void ) const { return ( this->_vector.size() ); }

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

int	Span::shortestSpan( void ) const {

	if ( this->_vector.size() < 2 )
		throw ( Span::NotEnoughElementsException() );

	std::vector<int>::iterator	i;
	std::vector<int>			tmp;
	int							r;

	tmp = this->_vector;
	std::sort( tmp.begin(), tmp.end() );

	r = *( tmp.begin() + 1 ) - *tmp.begin();
	for ( i = tmp.begin() + 1; i != tmp.end() - 1; i++ )
		if ( *( i + 1 ) - *i < r )
			r = *( i + 1 ) - *i;
	return ( r );
}

int	Span::longestSpan( void ) const {

	if ( this->_vector.size() < 2 )
		throw ( Span::NotEnoughElementsException() );

	std::vector<int>	tmp;

	tmp = this->_vector;
	std::sort( tmp.begin(), tmp.end() );

    return ( *( tmp.end() - 1 ) - *tmp.begin() );
}

void	Span::addNumber( int n ) {

	if ( this->_vector.size() >= this->_size )
		throw ( Span::NoMoreSpaceException() );
	this->_vector.push_back( n );
}

void	Span::addRandomNumber( int n ) {

	srand( time( NULL ));
	try {
		for ( int i = 0; i < n; i++ )
			this->addNumber( rand() );
	}
	catch ( std::exception& e ) { std::cout << e.what() << std::endl; }
}

/* ************************************************************************** */
/* Exceptions                                                                 */
/* ************************************************************************** */

char const* Span::IndexOutOfBoundsException::what( void ) const throw() {
	return ( "Span: Exception: index out of bounds" );
}

char const* Span::NotEnoughElementsException::what( void ) const throw() {
	return ( "Span: Exception: not enough space" );
}

char const* Span::NoMoreSpaceException::what( void ) const throw() {
	return ( "Span: Exception: no more space" );
}
