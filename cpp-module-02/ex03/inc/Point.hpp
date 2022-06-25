/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:11:59 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/06/25 14:03:55 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

/* ************************************************************************** */
/* Headers                                                                    */
/* ************************************************************************** */

# include <iostream>
# include "Fixed.hpp"
# include "Debug.hpp"

/* ************************************************************************** */
/* Class                                                                      */
/* ************************************************************************** */

class Point {

	public:

		/* Constructors and Destructors */
		Point( void );
		~Point( void );
		Point( Point const& src );

		Point( float const x, float const y );

		/* Operator Overload */
		Point	operator=( Point const& rhs );
		Point	operator+( Point const& rhs ) const;
		Point	operator-( Point const& rhs ) const;

		Fixed	operator*( Point const& rhs ) const;

		/* Getters and Setters */
		Fixed const& getX( void ) const;
		Fixed const& getY( void ) const;

		/* Other Functions */

	private:

		/* Private Constructors and Destructors */
		Point( Fixed x, Fixed y );

		/* Private Attributes */
		Fixed const	_x;
		Fixed const	_y;

};

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

std::ostream&	operator<<( std::ostream& os, Point const& rhs );

#endif /* POINT_HPP */
