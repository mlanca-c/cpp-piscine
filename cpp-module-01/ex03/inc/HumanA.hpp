/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:29:38 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/06/28 15:52:35 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

/* ************************************************************************** */
/* Headers                                                                    */
/* ************************************************************************** */

# include <iostream>
# include "Weapon.hpp"
# include "Debug.hpp"

/* ************************************************************************** */
/* Classes                                                                    */
/* ************************************************************************** */

class HumanA {

	public:

		/* Constructors and Destructors */
		~HumanA( void );
		HumanA( Weapon& weapon );
		HumanA( std::string name, Weapon& weapon );

		/* Getters and Setters */
		std::string const&	getName( void ) const;
		Weapon const&		getWeapon( void ) const;
		void				setName( std::string name );

		/* Other Functions */
		void	attack( void ) const;

	private:

		/* Private Attributes */
		std::string	_name;
		Weapon&		_weapon;

};

#endif /* HUMAN_A_HPP */
