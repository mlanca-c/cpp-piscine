/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Literal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:06:34 by mlancac           #+#    #+#             */
/*   Updated: 2022/10/05 19:07:31 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LITERAL_HPP
# define LITERAL_HPP

/* ************************************************************************** */
/* Headers                                                                    */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include <iomanip>
# include <limits>
# include <sstream>
# include "Debug.hpp"


/* ************************************************************************** */
/* Class                                                                      */
/* ************************************************************************** */

class Literal {

	public:

		enum t_type {
			CHAR,
			INT,
			FLOAT,
			DOUBLE,
			INF,
			INFF,
			NINF,
			NINFF,
			NAN,
			NANF
		};

		/* Constructors and Destructors */
		Literal( void );
		Literal( std::string str );
		~Literal( void );
		Literal( Literal const& src );

		/* Operator Overload */
		Literal&	operator=( Literal const& rhs );

		/* Getters and Setters */
		std::string		getValue( void ) const;
		Literal::t_type	getType( void ) const;

		/* Other Functions */
		void	print( void ) const;

	private:
		/* Private Getters and Setters */
		Literal::t_type	_setType( void );

		/* Other Private Functions */
		void	_print( char l ) const;
		void	_print( int l ) const;
		void	_print( float l ) const;
		void	_print( double l ) const;
		void	_printINF( void ) const;
		void	_printNINF( void ) const;
		void	_printNAN( void ) const;

		/* Private Attributes */
		std::string		_value;
		Literal::t_type	_type;
	
};

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

std::ostream&	operator<<( std::ostream& os, Literal const& rhs );

#endif /* LITERAL_HPP */
