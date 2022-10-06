/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:24:48 by mlancac           #+#    #+#             */
/*   Updated: 2022/09/27 09:16:37 by mlanca-c         ###   ########.fr       */
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

std::ostream&	operator<<( std::ostream& os, Cat const& rhs );

#endif /* CAT_HPP */
