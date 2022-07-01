/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:15:57 by mlancac           #+#    #+#             */
/*   Updated: 2022/07/01 13:15:32 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_ANIMAL_HPP
# define A_ANIMAL_HPP

/* ************************************************************************** */
/* Headers                                                                    */
/* ************************************************************************** */

# include <iostream>
# include "Debug.hpp"

/* ************************************************************************** */
/* Class                                                                      */
/* ************************************************************************** */

class AAnimal {

	public:

		/* Constructors and Destructors */
		AAnimal( void );
		virtual ~AAnimal( void );
		AAnimal( AAnimal const& src );

		/* Operator Overload */
		AAnimal&	operator=( AAnimal const& rhs );

		/* Getters and Setters */
		std::string	getType( void ) const;
		void		setType( std::string type );

		/* Other Functions */
		virtual void	makeSound( void ) const = 0;

	protected:

		AAnimal( std::string type );

		/* Private Attributes */
		std::string	_type;
	

};

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

std::ostream&	operator<<( std::ostream& os, AAnimal const& rhs );

#endif /* A_ANIMAL_HPP */
