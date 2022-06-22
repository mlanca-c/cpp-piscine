/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:52:49 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/22 14:25:39 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

/* ************************************************************************** */
/* Headers                                                                    */
/* ************************************************************************** */

# include <iostream>
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

		Fixed ( int i );
		Fixed ( float f );

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

#endif /* FIXED_HPP */
