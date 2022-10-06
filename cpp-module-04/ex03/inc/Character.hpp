/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:10:13 by mlancac           #+#    #+#             */
/*   Updated: 2022/09/27 10:56:56 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

/* ************************************************************************** */
/* Headers                                                                    */
/* ************************************************************************** */

# include <iostream>
# include "Debug.hpp"
# include "ICharacter.hpp"
# include "AMateria.hpp"

/* ************************************************************************** */
/* Class                                                                      */
/* ************************************************************************** */

class AMateria;

class Character : public ICharacter {

	public:

		/* Constructors and Destructors */
		~Character( void );
		Character( Character const& src );

		Character( std::string const& name );

		/* Operator Overload */
		Character&	operator=( Character const& rhs );

		/* Getters and Setters */
		std::string const&	getName( void ) const;
		AMateria*			getInventory( int idx ) const;
		int					getAmount( void ) const;

		/* Other Functions */
		void	equip( AMateria* m );
		void	unequip( int idx );
		void	use( int idx, ICharacter& target );

	private:

		/* Private Constructors and Destructors */
		Character( void );

		/* Private Attributes */
		std::string const	_name;
		AMateria*			_inventory[4];
		int					_amount;

};

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

std::ostream&	operator<<( std::ostream& os, Character const& rhs );

#endif /* CHARACTER_HPP */
