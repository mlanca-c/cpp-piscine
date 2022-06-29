/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:37:54 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/06/28 15:33:23 by mlanca-c         ###   ########.fr       */
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
/* Class                                                                    */
/* ************************************************************************** */

class Zombie {

	public:

		/* Constructors and Destructors */
		Zombie( std::string name );
		~Zombie( void );
		Zombie( void );

		/* Getters and Setters */
		std::string	getName( void ) const;
		void		setName( std::string name );

		/* Other Functions */
		void	anounce( void );

	private:

		/* Private Attributes */
		std::string	_name;

};

/* ************************************************************************** */
/* Funtion Prototypes                                                         */
/* ************************************************************************** */

Zombie*	zombieHorde( int N, std::string name );

#endif /* ZOMBIE_HPP */
