/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:19:28 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/06/29 11:17:52 by mlanca-c         ###   ########.fr       */
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
		static const int	_fBits;

};

#endif /* FIXED_HPP */
