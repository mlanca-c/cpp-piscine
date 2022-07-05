/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LiteralCast.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:50:23 by mlancac           #+#    #+#             */
/*   Updated: 2022/07/05 16:14:58 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LITERAL_CAST_HPP
# define LITERAL_CAST_HPP

/* ************************************************************************** */
/* Headers                                                                    */
/* ************************************************************************** */

# include <iostream>
# include <exception>
# include <sstream>
# include <limits>
# include <iostream>
# include <iomanip>
# include "Debug.hpp"

/* ************************************************************************** */
/* Class                                                                      */
/* ************************************************************************** */

typedef enum	e_type {
	None,
	Char,
	Int,
	Float,
	Double,
	Inf,
	// Inff,
	NInf,
	// NInff,
	Nan,
	// Nanf,
}	t_type;

// 1: detect the type of the literal
// 2: convert from str to its type
// 3: convert explicitly to three other data types
// 	( if conversion doesnt make sense or overfloes impossible )

class LiteralCast {

	public:

		/* Constructors and Destructors */
		~LiteralCast( void );
		LiteralCast( LiteralCast const& src );

		LiteralCast( std::string const& literal );

		/* Operator Overload */
		LiteralCast&	operator=( LiteralCast const& rhs );

		/* Getters and Setters */
		std::string	getLiteral( void ) const;
		t_type		getType( void ) const;

		/* Other Functions */
		void	printCast( void ) const;

	private:

		/* Private Constructors and Destructors */
		LiteralCast( void );

		/* Other Functions */
		void	printLiteral( char c ) const;
		void	printLiteral( int i ) const;
		void	printLiteral( float f ) const;
		void	printLiteral( double d ) const;

		void	printChar( char c ) const;
		void	printInt( int i ) const;
		void	printFloat( float f ) const;
		void	printDouble( double d ) const;

		t_type	generateType( void );
		void	printInt( void ) const;
		void	printChar( void ) const;
		void	printFloat( void ) const;
		void	printDouble( void ) const;

		/* Private Attributes */
		std::string const	_literal;
		t_type				_type;

};

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

std::ostream&	operator<<( std::ostream& os, LiteralCast const& rhs );

#endif /* LITERAL_CAST_HPP */
