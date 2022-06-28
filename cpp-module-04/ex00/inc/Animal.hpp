/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:03:40 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/28 15:28:45 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

/* ************************************************************************** */
/* Headers                                                                    */
/* ************************************************************************** */

# include <iostream>
# include "Debug.hpp"

/* ************************************************************************** */
/* Class                                                                      */
/* ************************************************************************** */

class Animal {

	public:

		/* Constructors and Destructors */
		Animal( void );
		virtual ~Animal( void );
		Animal( Animal const& src );

		Animal( std::string type );

		/* Operator Overload */
		Animal&	operator=( Animal const& rhs );

		/* Getters and Setters */
		std::string	getType( void ) const;
		void		setType( std::string type );

		/* Other Functions */
		virtual void	makeSound( void ) const;

	protected:

		/* Private Attributes */
		std::string	_type;

};

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

std::ostream&	operator<<( std::ostream& os, Animal const& rhs );

#endif /* ANIMAL_HPP */
