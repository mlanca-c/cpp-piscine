/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Literal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 19:12:05 by mlancac           #+#    #+#             */
/*   Updated: 2022/07/05 20:41:03 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LITERAL_HPP
# define LITERAL_HPP

/* ************************************************************************** */
/* Headers                                                                    */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include <limits>
# include <sstream>
# include "Debug.hpp"

/* ************************************************************************** */
/* Other Strucs or Enums                                                      */
/* ************************************************************************** */

typedef enum e_types {
	Invalid,
	Char,
	Int,
	Float,
	Double,
	Inf,
	Inff,
	NInf,
	NInff,
	Nan,
	Nanf,
}	t_type;

/* ************************************************************************** */
/* Class                                                                      */
/* ************************************************************************** */

class Literal {

	public:

		/* Constructors and Destructors */
		~Literal( void );
		Literal( Literal const& src );

		Literal( std::string const& value );

		/* Operator Overload */
		Literal&	operator=( Literal const& rhs );

		/* Getters and Setters */
		std::string const&	getValue( void ) const;
		t_type				getType( void ) const;

		/* Other Functions */
		void	printValues( void ) const;

	private:

		/* Private Constructors and Destructors */
		Literal( void );

		/* Other Private Functions */
		void	printValues( char c ) const;
		void	printValues( int i ) const;
		void	printValues( float f ) const;
		void	printValues( double d ) const;

		/* Private Attributes */
		std::string const	_value;
		t_type				_type; 
	

};

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

std::ostream&	operator<<( std::ostream& os, Literal const& rhs );

#endif /* LITERAL_HPP */
