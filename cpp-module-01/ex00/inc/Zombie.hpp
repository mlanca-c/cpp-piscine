/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:37:54 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/06/26 13:57:47 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

/* ************************************************************************** */
/* Headers                                                                    */
/* ************************************************************************** */

# include <iostream>
# include "Debug.hpp"

/* ************************************************************************** */
/* Classes                                                                    */
/* ************************************************************************** */

class Zombie {

	public:

		/* Constructors and Destructors */
		Zombie( std::string name );
		~Zombie( void );

		/* Getters and Setters */
		std::string	getName( void ) const;
		void		setName( std::string name );

		/* Other Functions */
		void	anounce( void );

	private:

		/* Private Constructors and Destructors */
		Zombie( void );

		/* Private Attributes */
		std::string	_name;

};

/* ************************************************************************** */
/* Funtion Prototypes                                                         */
/* ************************************************************************** */

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif /* ZOMBIE_HPP */
