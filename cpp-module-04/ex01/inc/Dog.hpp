/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:30:19 by mlancac           #+#    #+#             */
/*   Updated: 2022/09/27 09:16:45 by mlanca-c         ###   ########.fr       */
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
# include "Brain.hpp"

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
		Brain*		getBrain( void ) const;
		
		/* Other Functions */
		void	makeSound( void ) const;

	private:
	
		/* Private Attributes */
		Brain*		_brain;
		
};

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

std::ostream&	operator<<( std::ostream& os, Dog const& rhs );

#endif /* DOG_HPP */
