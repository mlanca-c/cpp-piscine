/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:06:44 by mlancac           #+#    #+#             */
/*   Updated: 2022/07/03 19:19:03 by mlancac          ###   ########.fr       */
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

		/* Getters and Setters */
		virtual std::string const&	getName( void ) const = 0;

		/* Other Functions */
		virtual void	equip( AMateria* m ) = 0;
		virtual void	unequip( int idx ) = 0;
		virtual void	use( int idx, ICharacter& target ) = 0;

};

#endif /* I_CHARACTER_HPP */
