/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:52:49 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/22 16:55:59 by mlanca-c         ###   ########.fr       */
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
		~Fixed( void );
		Fixed( Fixed const& src );

		Fixed ( int const i );
		Fixed ( float const f );

		/* Operator Overload */
		Fixed&	operator=( Fixed const& rhs );

		/* Getters and Setters */
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		/* Other Functions */
		int		toInt( void ) const;
		float	toFloat( void ) const;

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
