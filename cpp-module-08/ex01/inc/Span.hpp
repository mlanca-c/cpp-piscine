/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:16:02 by mlancac           #+#    #+#             */
/*   Updated: 2022/10/07 14:56:59 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

/* ************************************************************************** */
/* Headers                                                                    */
/* ************************************************************************** */

# include <iostream>
# include "Debug.hpp"
# include "algorithm"
# include "vector"
# include "time.h"

/* ************************************************************************** */
/* Class                                                                      */
/* ************************************************************************** */

class Span {

	public:

		/* Constructors and Destructors */
		~Span( void );
		Span( Span const& src );

		Span( unsigned int size );

		/* Operator Overload */
		Span&	operator=( Span const& rhs );
		int const&	operator[]( unsigned int i ) const;

		/* Getters and Setters */
		unsigned int	getSize( void ) const;

		/* Other Functions */
		int	shortestSpan( void ) const;
		int	longestSpan( void ) const;

		void	addNumber( int n );
		void	addRandomNumber( int n );

		/* Exceptions */
		class	IndexOutOfBoundsException : public std::exception {
			public:
				char const* what( void ) const throw();
		};

		class	NotEnoughElementsException : public std::exception {
			public:
				char const* what( void ) const throw();
		};

		class	NoMoreSpaceException : public std::exception {
			public:
				char const* what( void ) const throw();
		};

	private:

		/* Private Constructors and Destructors */
		Span( void );

		/* Private Attributes */
		unsigned int		_size;
		std::vector<int>	_vector;
};

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

std::ostream&	operator<<( std::ostream& os, Span const& rhs );

#endif /* SPAN_HPP */
