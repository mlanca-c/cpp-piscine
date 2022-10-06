/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:30:19 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/30 16:36:27 by mlancac          ###   ########.fr       */
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

		/* Other Functions */
		void	makeSound( void ) const;

};

#endif /* DOG_HPP */
