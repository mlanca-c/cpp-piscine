/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:50:00 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/06/28 15:47:55 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

/* ************************************************************************** */
/* Headers                                                                    */
/* ************************************************************************** */

# include <iostream>
# include "Weapon.hpp"
# include "Debug.hpp"

/* ************************************************************************** */
/* Classes                                                                    */
/* ************************************************************************** */

class HumanB {

	public:

		/* Constructors and Destructors */
		HumanB( void );
		~HumanB( void );
		HumanB( std::string name );

		/* Getters and Setters */
		std::string const&	getName( void ) const;
		Weapon const*		getWeapon( void ) const;
		void				setName( std::string name );
		void				setWeapon( Weapon& weapon );

		/* Other Functions */
		void	attack( void ) const;

	private:

		/* Private Attributes */
		std::string	_name;
		Weapon*		_weapon;

};

#endif /* HUMAN_B_HPP */
