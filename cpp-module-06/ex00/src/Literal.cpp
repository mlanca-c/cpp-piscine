/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Literal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 19:18:35 by mlancac           #+#    #+#             */
/*   Updated: 2022/07/05 20:39:58 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Literal.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

Literal::Literal( void ) : _value( "0" ) {

	this->_type = Int;
	DEBUG( "<Literal> default constructor called" );
}

Literal::~Literal( void ) { DEBUG( "<Literal> destructor called" ); }

Literal::Literal( Literal const& src )
	: _value( src._value ), _type( src._type ){
	DEBUG( "<Literal> copy constructor called" );
}

Literal::Literal( std::string const& value ) : _value( value ) {

	if ( this->_value == "inf" || this->_value == "+inf" )
		this->_type = Inf;
	else if ( this->_value == "inff" || this->_value == "+inff" )
		this->_type = Inff;
	else if ( this->_value == "-inf" )
		this->_type = NInf;
	else if ( this->_value == "-inff" )
		this->_type = NInff;
	else if ( this->_value == "nan" )
		this->_type = Nan;
	else if ( this->_value == "nanf" )
		this->_type = Nanf;
	else if ( this->_value.length() == 1 && !std::isdigit( this->_value[0] ))
		this->_type = Char;
	else if ( this->_value.find( 'f' ) != std::string::npos )
		this->_type = Float;
	else if ( this->_value.find( '.' ) != std::string::npos )
		this->_type = Double;
	else
		this->_type = Int;
	
	DEBUG( "<Literal> " << this->_value << " of type " << this->_type
	   << " constructor called" );
}

/* ************************************************************************** */
/* Operator Overload                                                          */
/* ************************************************************************** */

Literal&	Literal::operator=( Literal const& rhs ) {

	// const_cast<std::string>( this->_value ) = rhs._value;
	this->_type = rhs._type;
	return ( *this );
}

std::ostream&	operator<<( std::ostream& os, Literal const& rhs ) {

	os << "<Literal> " << rhs.getValue() << " of type " << rhs.getType();
	return ( os );
}

/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */

std::string const&	Literal::getValue( void ) const { return ( this->_value ); }

t_type	Literal::getType( void ) const { return ( this->_type ); }

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

void	Literal::printValues( void ) const {
	
	std::stringstream	ss;

	ss << this->_value;
	switch ( static_cast<int>( this->_type )) {

		case Char:
			char	c;
			ss >> c;
			return ( printValues( c ));

		case Int:
			int	i;
			ss >> i;
			return ( printValues( i ));

		case Float:
			float	f;
			ss >> f;
			return ( printValues( f ));

		case Double:
			double	d;
			ss >> d;
			return ( printValues( d ));

		case Inf:
		case Inff:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: inff" << std::endl;
			std::cout << "double: inf" << std::endl;
			break ;

		case NInf:
		case NInff:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
			break ;

		case Nan:
		case Nanf:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
			break ;

	}
}

void	Literal::printValues( char c ) const {

	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>( c ) << std::endl;
	std::cout << "float: " << static_cast<float>( c ) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>( c ) << ".0" << std::endl;
}

void	Literal::printValues( int i ) const {

	if ( i < std::numeric_limits<char>::min()
		|| i > std::numeric_limits<char>::max() )
		std::cout << "char: impossible" << std::endl;
	else if ( !std::isprint( i ))
		std::cout << "char: Non Displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>( i ) << std::endl;

	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>( i ) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>( i ) << ".0" << std::endl;
}

void	Literal::printValues( float f ) const {

	if ( f < std::numeric_limits<char>::min()
		|| f > std::numeric_limits<char>::max() )
		std::cout << "char: impossible" << std::endl;
	else if ( !std::isprint( f ))
		std::cout << "char: Non Displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>( f ) << std::endl;

	if ( f < std::numeric_limits<int>::min()
		|| f > std::numeric_limits<int>::max() )
	 	std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>( f ) << std::endl;

	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>( f ) << std::endl;
}

void	Literal::printValues( double d ) const {

	if ( d < std::numeric_limits<char>::min()
		|| d > std::numeric_limits<char>::max() )
		std::cout << "char: impossible" << std::endl;
	else if ( !std::isprint( d ))
		std::cout << "char: Non Displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>( d ) << std::endl;

	if ( d < std::numeric_limits<int>::min()
		|| d > std::numeric_limits<int>::max() )
	 	std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>( d ) << std::endl;

	ERROR("try: -4.2");
	if ( d < std::numeric_limits<float>::min()
		|| d > std::numeric_limits<float>::max() )
	 	std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << static_cast<float>( d ) << "f" << std::endl;

	std::cout << "double: " << d << std::endl;
}
