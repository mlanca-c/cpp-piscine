/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Literal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:20:52 by mlancac           #+#    #+#             */
/*   Updated: 2022/10/05 19:13:25 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Literal.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

Literal::Literal( void ) : _value( "0" ), _type( INT ) {
	DEBUG( "Literal <" << this->_value << "> default constructor called" );
}
Literal::Literal( std::string str ) : _value( str ) {

	this->_type = this->_setType();
	DEBUG( "Literal <" << this->_value << "> constructor called" );
}

Literal::~Literal( void ) {
	DEBUG( "Literal <" << this->_value << "> destructor called" );
}

Literal::Literal( Literal const& src ) {

	*this = src;
	DEBUG( "Literal <" << this->_value << "> copy constructor called" );
}

/* ************************************************************************** */
/* Operator Overload                                                          */
/* ************************************************************************** */

Literal&	Literal::operator=( Literal const& rhs ) {

	this->_value = rhs._value;
	this->_type = rhs._type;
	return ( *this );
}

std::ostream&	operator<<( std::ostream& os, Literal const& rhs ) {

	std::string	types[10] = { "char", "int", "float", "double", "inf", "-inf",
		"inff", "-inff", "nan", "-nan" };

	os << "Literal <" << rhs.getValue() << ">: "
	   << types[rhs.getType()];
	return ( os );
}

/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */

std::string	Literal::getValue( void ) const { return ( this->_value ); }

Literal::t_type	Literal::getType( void ) const { return ( this->_type ); }

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

Literal::t_type	Literal::_setType( void ) {

	if ( this->_value == "inf" || this->_value == "+inf" )
		return ( INF );
	else if ( this->_value == "inff" || this->_value == "+inff" )
		return ( INFF );
	else if ( this->_value == "-inf" )
		return ( NINF );
	else if ( this->_value == "-inff" )
		return ( NINFF );
	else if ( this->_value == "nan" )
		return ( NAN );
	else if ( this->_value == "nanf" )
		return ( NANF );
	else if ( this->_value.length() == 1 && !std::isdigit( this->_value[ 0 ] ))
		return ( CHAR );
	else if ( this->_value.find( 'f' ) != std::string::npos )
		return ( FLOAT );
	else if ( this->_value.find( '.' ) != std::string::npos )
		return ( DOUBLE );
	return ( INT );
}

void	Literal::print( void ) const {

	std::stringstream	s;
	s << this->_value;

	switch( static_cast<int>( this->_type )) {

		case CHAR:
			char c; s >> c; return ( this->_print( c ));

		case INT:
			int i; s >> i; return ( this->_print( i ));

		case FLOAT:
			float f; s >> f; return ( this->_print( f ));

		case DOUBLE:
			double	d; s >> d; return ( this->_print( d ));

		case INF:
		case INFF:
			return ( this->_printINF() );

		case NINF:
		case NINFF:
			return ( this->_printNINF() );

		case NAN:
		case NANF:
			return ( this->_printNAN() );
	}
}

void	Literal::_print( char l ) const {
	std::cout << "char: " << l << std::endl;
	std::cout << "int: " << static_cast<int>( l ) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1)
			  << static_cast<float>( l ) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1)
			  << static_cast<double>( l ) << std::endl;
}

void	Literal::_print( int l ) const {

	if ( l < std::numeric_limits<char>::min() ||
		l > std::numeric_limits<char>::max() )
		std::cout << "char: impossible" << std::endl;
	else if ( !std::isprint( l ))
		std::cout << "char: non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>( l ) << std::endl;

	std::cout << "int: " << l << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1)
			  << static_cast<float>( l ) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1)
			  << static_cast<double>( l ) << std::endl;
}

void	Literal::_print( float l ) const {

	if ( l < std::numeric_limits<char>::min() ||
		l > std::numeric_limits<char>::max() )
		std::cout << "char: impossible" << std::endl;
	else if ( !std::isprint( l ))
		std::cout << "char: non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>( l ) << std::endl;

	std::cout << "int: " << static_cast<int>( l ) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1)
			  << l << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1)
			  << static_cast<double>( l ) << std::endl;
}

void	Literal::_print( double l ) const {

	if ( l < std::numeric_limits<char>::min() ||
		l > std::numeric_limits<char>::max() )
		std::cout << "char: impossible" << std::endl;
	else if ( !std::isprint( l ))
		std::cout << "char: non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>( l ) << std::endl;

	std::cout << "int: " << static_cast<int>( l ) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1)
			  << static_cast<float>( l ) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1)
			  << l << std::endl;
}

void	Literal::_printINF( void ) const {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: inff" << std::endl;
	std::cout << "double: inf" << std::endl;
}

void	Literal::_printNINF( void ) const {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: -inff" << std::endl;
	std::cout << "double: -inf" << std::endl;
}

void	Literal::_printNAN( void ) const {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}
