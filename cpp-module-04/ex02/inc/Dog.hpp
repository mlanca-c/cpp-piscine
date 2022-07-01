/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:30:19 by mlancac           #+#    #+#             */
/*   Updated: 2022/07/01 13:16:08 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

/* ************************************************************************** */
/* Headers                                                                    */
/* ************************************************************************** */

# include <iostream>
# include "Debug.hpp"
# include "AAnimal.hpp"
# include "Brain.hpp"

/* ************************************************************************** */
/* Class                                                                      */
/* ************************************************************************** */

class Dog : public AAnimal {

	public:

		/* Constructors and Destructors */
		Dog( void );
		~Dog( void );
		Dog( Dog const& src );

		/* Operator Overload */
		Dog&	operator=( Dog const& rhs );

		/* Other Functions */
		void	makeSound( void ) const;

		/* Getters and Setters */
		Brain*	getBrain( void ) const;
		// void	setBrain( Brain* brain );

	private:

		/* Private Attributes */
		Brain*	_brain;

};

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

std::ostream&	operator<<( std::ostream& os, Dog const& rhs );

#endif /* DOG_HPP */
