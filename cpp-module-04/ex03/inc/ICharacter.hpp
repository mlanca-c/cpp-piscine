/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:44:05 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/07/01 16:19:15 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_CHARACTER_HPP
# define I_CHARACTER_HPP

/* ************************************************************************** */
/* Headers                                                                    */
/* ************************************************************************** */

# include <iostream>
# include "Debug.hpp"
# include "AMateria.hpp"

/* ************************************************************************** */
/* Class                                                                      */
/* ************************************************************************** */

class AMateria;

class ICharacter {

	public:

		/* Constructors and Destructors */
		virtual ~ICharacter( void ) {};

		/* Operator Overload */
		virtual std::string const&	getName( void ) const = 0;

		/* Getters and Setters */

		/* Other Functions */
		virtual void	equip( AMateria* m ) = 0;
		virtual void	unequip( int idx ) = 0;
		virtual void	use( int idx, ICharacter &target ) = 0;

};

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

std::ostream&	operator<<( std::ostream& os, ICharacter const& rhs );

#endif /* I_CHARACTER_HPP */
