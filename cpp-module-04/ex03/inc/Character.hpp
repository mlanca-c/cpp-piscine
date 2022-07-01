/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:57:58 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/07/01 16:02:35 by mlanca-c         ###   ########.fr       */
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

class Character : public ICharacter {

	public:

		/* Constructors and Destructors */
		Character( void );
		~Character( void );
		Character( Character const& src );

		Character( std::string const& name );

		/* Operator Overload */
		Character&	operator=( Character const& rhs );

		/* Getters and Setters */
		std::string const&	getName( void ) const;

		/* Other Functions */
		void	equip( AMateria* m );
		void	unequip( int idx );
		void	use( int idx, ICharacter &target );


	private:

		/* Private Attributes */
		std::string	_name;
		AMateria	_inventory[4];

};

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

std::ostream&	operator<<( std::ostream& os, Character const& rhs );

#endif /* CHARACTER_HPP */
