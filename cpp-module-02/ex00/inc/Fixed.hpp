/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:52:49 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/22 14:04:46 by mlancac          ###   ########.fr       */
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

		/* Operator Overload */
		Fixed&	operator=( Fixed const& rhs );

		/* Getters and Setters */
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:

		/* Private Attributes */
		int					_raw;
		static const int	_fBits = 8;

};

#endif /* FIXED_HPP */
