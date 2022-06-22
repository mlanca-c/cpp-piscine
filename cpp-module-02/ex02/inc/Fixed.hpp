/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:52:49 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/22 17:24:36 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

/* ************************************************************************** */
/* Headers                                                                    */
/* ************************************************************************** */

# include <iostream>
# include <cmath>
# include "Debug.hpp"

/* ************************************************************************** */
/* Class                                                                      */
/* ************************************************************************** */

class Fixed {

	public:

		/* Constructor and Destructor */
		Fixed( void );
		Fixed( Fixed const& src );
		~Fixed( void );

		Fixed ( int const i );
		Fixed ( float const f );

		/* Operator Overload */
		Fixed&	operator=( Fixed const& rhs );

		bool	operator<( Fixed const& rhs ) const;
		bool	operator>( Fixed const& rhs ) const;
		bool	operator<=( Fixed const& rhs ) const;
		bool	operator>=( Fixed const& rhs ) const;
		bool	operator==( Fixed const& rhs ) const;
		bool	operator!=( Fixed const& rhs ) const;

		Fixed	operator+( void ) const;
		Fixed	operator-( void ) const;
		Fixed	operator+( Fixed const& rhs ) const;
		Fixed	operator-( Fixed const& rhs ) const;
		Fixed	operator*( Fixed const& rhs ) const;
		Fixed	operator/( Fixed const& rhs ) const;

		Fixed	operator++( void );
		Fixed	operator--( void );
		Fixed&	operator++( int );
		Fixed&	operator--( int );

		/* Getters and Setters */
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		/* Other Functions */
		int		toInt( void ) const;
		float	toFloat( void ) const;

		static Fixed const&	max( Fixed const& lhs, Fixed const& rhs ) const;
		static Fixed&		max( Fixed& lhs, Fixed& rhs ) const;
		static Fixed const&	min( Fixed const& lhs, Fixed const& rhs ) const;
		static Fixed&		min( Fixed& lhs, Fixed& rhs ) const;

	private:

		/* Private Attributes */
		int					_raw;
		static const int	_fBits = 8;

};

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

std::ostream&	operator<<( std::ostream& os, Fixed const& rhs );

#endif /* FIXED_HPP */
