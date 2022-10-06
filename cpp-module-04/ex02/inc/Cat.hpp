/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:24:48 by mlancac           #+#    #+#             */
/*   Updated: 2022/09/27 09:34:52 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

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

class Cat : public AAnimal {

	public:

		/* Constructors and Destructors */
		Cat( void );
		~Cat( void );
		Cat( Cat const& src );

		/* Operator Overload */
		Cat&	operator=( Cat const& rhs );

		/* Other Functions */
		void	makeSound( void ) const;

	private:

};

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

std::ostream&	operator<<( std::ostream& os, Cat const& rhs );

#endif /* CAT_HPP */
