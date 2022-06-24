/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:11:59 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/06/24 12:57:47 by mlancac          ###   ########.fr       */
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

		/* Getters and Setters */
		Fixed const& getX( void ) const;
		Fixed const& getY( void ) const;

		/* Other Functions */
		static Fixed area( Point const a, Point const b, Point const c);

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
