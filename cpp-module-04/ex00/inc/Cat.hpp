/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:04:33 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/28 15:11:53 by mlancac          ###   ########.fr       */
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

		/* Getters and Setters */

		/* Other Functions */
		void	makeSound( void ) const;

	private:

		/* Private Attributes */
	

};

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

std::ostream&	operator<<( std::ostream& os, Cat const& rhs );

#endif /* CAT_HPP */
