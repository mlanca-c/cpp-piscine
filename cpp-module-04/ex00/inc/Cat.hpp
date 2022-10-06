/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:24:48 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/30 16:36:54 by mlancac          ###   ########.fr       */
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

		/* Other Functions */
		void	makeSound( void ) const;

};

#endif /* CAT_HPP */
