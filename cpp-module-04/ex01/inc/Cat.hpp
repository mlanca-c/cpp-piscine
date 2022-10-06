/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:24:48 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/30 17:23:30 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

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

class Cat : public Animal {

	public:

		/* Constructors and Destructors */
		Cat( void );
		~Cat( void );
		Cat( Cat const& src );

		/* Operator Overload */
		Cat&	operator=( Cat const& rhs );

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

std::ostream&	operator<<( std::ostream& os, Cat const& rhs );

#endif /* CAT_HPP */
