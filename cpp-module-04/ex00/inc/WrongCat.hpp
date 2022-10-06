/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:39:21 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/30 16:40:09 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

/* ************************************************************************** */
/* Headers                                                                    */
/* ************************************************************************** */

# include <iostream>
# include "Debug.hpp"
# include "WrongAnimal.hpp"

/* ************************************************************************** */
/* Class                                                                      */
/* ************************************************************************** */

class WrongCat : public WrongAnimal {

	public:

		/* Constructors and Destructors */
		WrongCat( void );
		~WrongCat( void );
		WrongCat( WrongCat const& src );

		/* Operator Overload */
		WrongCat&	operator=( WrongCat const& rhs );

		/* Other Functions */
		void	makeSound( void ) const;

};

#endif /* WRONG_CAT_HPP */
