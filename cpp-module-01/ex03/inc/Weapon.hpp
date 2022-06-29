/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:53:15 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/06/28 15:47:25 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

/* ************************************************************************** */
/* Headers                                                                    */
/* ************************************************************************** */

# include <iostream>
# include "Debug.hpp"

/* ************************************************************************** */
/* Classes                                                                    */
/* ************************************************************************** */

class Weapon {

	public:

		/* Constructors and Destructors */
		Weapon( void );
		~Weapon( void );
		Weapon( std::string type );

		/* Getters and Setters */
		std::string const&	getType( void ) const;
		void				setType( std::string type );

		/* Other Functions */

	private:

		/* Private Attributes */
		std::string	_type;

};

/* ************************************************************************** */
/* Funtion Prototypes                                                         */
/* ************************************************************************** */

#endif /* WEAPON_HPP */
