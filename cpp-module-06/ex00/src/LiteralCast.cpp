/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LiteralCast.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:54:20 by mlancac           #+#    #+#             */
/*   Updated: 2022/07/05 16:23:38 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LiteralCast.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

LiteralCast::LiteralCast( void ) : _literal( "42" ) {

	this->_type = generateType();
	DEBUG( "<LiteralCast> default constructor called" );
}

LiteralCast::~LiteralCast( void ) {
	DEBUG( "<LiteralCast> destructor called" );
}

LiteralCast::LiteralCast( LiteralCast const& src )
	: _literal( src._literal ), _type( src._type ) {
	DEBUG( "<LiteralCast> copy constructor called" );
}

LiteralCast::LiteralCast( std::string const& literal ) : _literal( literal ) {

	this->_type = generateType();
	DEBUG( "<LiteralCast> " << this->_literal << " constructor called" );
}

/* ************************************************************************** */
/* Operator Overload                                                          */
/* ************************************************************************** */

LiteralCast&	LiteralCast::operator=( LiteralCast const& rhs ) {

	const_cast<std::string&>( this->_literal ) = rhs._literal;
	this->_type = rhs._type;
	return ( *this );
}

std::ostream&	operator<<( std::ostream& os, LiteralCast const& rhs ) {

	os << "convert " << rhs.getLiteral();
	return ( os );
}

/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */

std::string	LiteralCast::getLiteral( void ) const { return ( this->_literal ); }

t_type	LiteralCast::getType( void ) const { return ( this->_type ); }

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

void	LiteralCast::printCast( void ) const {

	std::stringstream	sStream;

	sStream << this->_literal;
	if ( this->_type == Char ) {

		char	c;
		sStream >> c;
		printLiteral( c );
	}
	else if ( this->_type == Int ) {

		int	i;
		sStream >> i;
		printLiteral( i );
	}
	else if ( this->_type == Float ) {

		float	f;
		sStream >> f;
		printLiteral( f );
	}
	else if ( this->_type == Double ) {

		double	d;
		sStream >> d;
		printLiteral( d );
	}
	else if ( this->_type == Inf ) {

		std::cout << "char:   impossible" << std::endl;
		std::cout << "int:    impossible" << std::endl;
		std::cout << "float:  inff" << std::endl;
		std::cout << "double: inf" << std::endl;
	}
	else if ( this->_type == NInf ) {

		std::cout << "char:   impossible" << std::endl;
		std::cout << "int:    impossible" << std::endl;
		std::cout << "float:  -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else if ( this->_type == Nan ) {

		std::cout << "char:   impossible" << std::endl;
		std::cout << "int:    impossible" << std::endl;
		std::cout << "float:  nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else { ERROR( "invalid literal" ); }
}

void	LiteralCast::printLiteral( char c ) const {

	printChar( c );
	printInt( static_cast<int>( c ));
	printFloat( static_cast<float>( c ));
	printDouble( static_cast<double>( c ));
}

void	LiteralCast::printLiteral( int i ) const {

	if ( i <= std::numeric_limits<char>::max()
			&& i >= std::numeric_limits<char>::min() )
		printChar( static_cast<char>( i ));
	else
        std::cout << "char: impossible" << std::endl;
	printInt( i );
	printFloat( static_cast<float>( i ));
	printDouble( static_cast<double>( i ));
}

void	LiteralCast::printLiteral( float f ) const {

	if ( f <= std::numeric_limits<char>::max()
			&& f >= std::numeric_limits<char>::min() )
		printChar( static_cast<char>( f ));
	else
		std::cout << "char: impossible" << std::endl;

	if ( f <= std::numeric_limits<int>::max()
			&& f >= std::numeric_limits<int>::min() )
		printInt( static_cast<int>( f ));
	else
        std::cout << "int: impossible" << std::endl;

	printFloat( f );

	printDouble( static_cast<double>( f ));
}

void	LiteralCast::printLiteral( double d ) const {

	if ( d <= std::numeric_limits<char>::max()
			&& d >= std::numeric_limits<char>::min() )
		printChar( static_cast<char>( d ));
	else
        std::cout << "char: impossible" << std::endl;

	if ( d <= std::numeric_limits<int>::max()
			&& d >= std::numeric_limits<int>::min() )
		printInt( static_cast<int>( d ));
	else
        std::cout << "int: impossible" << std::endl;

	if ( d <= std::numeric_limits<float>::max()
			&& d >= std::numeric_limits<float>::min() )
		printFloat( static_cast<float>( d ));
	else
        std::cout << "float: impossible" << std::endl;

	printDouble( d );
	
}

t_type	LiteralCast::generateType( void ) {

	if ( this->_literal.length() == 0 ) return ( None );
	if ( this->_literal == "+inff" || this->_literal == "inff" )
		return ( Inf );
	if ( this->_literal == "-inff" ) return ( NInf );
	if ( this->_literal == "nanf" ) return ( Nan );
	if ( this->_literal == "+inf" || this->_literal == "inf" ) return ( Inf );
	if ( this->_literal == "-inf" ) return ( NInf );
	if ( this->_literal == "nan" ) return ( Nan );
	if ( this->_literal.length() == 1 && !isdigit( this->_literal[0] ))
		return ( Char );
	if ( this->_literal.find( 'f' ) != std::string::npos ) return ( Float );
	if ( this->_literal.find( '.' ) != std::string::npos ) return ( Double );
	return ( Int );
}

void	LiteralCast::printChar( char c ) const {
	
    if ( std::isprint(c) )
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void	LiteralCast::printInt( int i ) const {
	std::cout << "int: " << i << std::endl;
}

void	LiteralCast::printFloat( float f ) const {

	if ( this->_literal.find( '.' ) == std::string::npos )
		std::cout << "float: " << f << ".0f" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;
}

void	LiteralCast::printDouble( double d ) const {

	if ( this->_literal.find( '.' ) == std::string::npos )
		std::cout << "float: " << d << ".0" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}
