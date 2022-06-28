/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:04:39 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/28 15:22:36 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

/* ************************************************************************** */
/* Headers                                                                    */
/* ************************************************************************** */

# include <iostream>
# include "Debug.hpp"
# include "Animal.hpp"

/* ************************************************************************** */
/* Class                                                                      */
/* ************************************************************************** */

class Dog : public Animal {

	public:

		/* Constructors and Destructors */
		Dog( void );
		~Dog( void );
		Dog( Dog const& src );

		/* Operator Overload */
		Dog&	operator=( Dog const& rhs );

		/* Getters and Setters */

		/* Other Functions */
		void	makeSound( void ) const;

	private:

		/* Private Attributes */
	

};

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

std::ostream&	operator<<( std::ostream& os, Dog const& rhs );

#endif /* DOG_HPP */
