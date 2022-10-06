/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:29:20 by mlancac           #+#    #+#             */
/*   Updated: 2022/07/07 12:57:06 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

/* ************************************************************************** */
/* Headers                                                                    */
/* ************************************************************************** */

# include <iostream>
# include <exception>
# include <vector>
# include <numeric>
# include <algorithm>
# include "Debug.hpp"

/* ************************************************************************** */
/* Class                                                                      */
/* ************************************************************************** */

class Span {

	public:

		/* Constructors and Destructors */
		~Span( void );
		Span( Span const& src );

		Span( unsigned int N );

		/* Operator Overload */
		Span&	operator=( Span const& rhs );

		/* Getters and Setters */
		unsigned int	size( void ) const;

		/* Other Functions */
		void	addNumber( int n ) throw( std::exception );
		void	addNumbers(std::vector<int>::iterator it1,
				std::vector<int>::iterator it2 ) throw( std::exception );
		int		shortestSpan( void ) const throw( std::exception );
		int		longestSpan( void ) const throw( std::exception );

		/* Exceptions */

	private:

		/* Private Constructors and Destructors */
		Span( void );

		/* Private Attributes */
		unsigned int		_size;
		std::vector<int>	_vect;
	

};

#endif /* SPAN_HPP */
