/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:37:40 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/30 16:38:25 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

/* ************************************************************************** */
/* Headers                                                                    */
/* ************************************************************************** */

# include <iostream>
# include "Debug.hpp"

/* ************************************************************************** */
/* Class                                                                      */
/* ************************************************************************** */

class WrongAnimal {

	public:

		/* Constructors and Destructors */
		WrongAnimal( void );
		~WrongAnimal( void );
		WrongAnimal( WrongAnimal const& src );

		/* Operator Overload */
		WrongAnimal&	operator=( WrongAnimal const& rhs );

		/* Getters and Setters */
		std::string	getType( void ) const;
		void		setType( std::string type );

		/* Other Functions */
		void	makeSound( void ) const;

	protected:

		WrongAnimal( std::string type );

		/* Private Attributes */
		std::string	_type;
	

};

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

std::ostream&	operator<<( std::ostream& os, WrongAnimal const& rhs );

#endif /* WRONG_ANIMAL_HPP */
