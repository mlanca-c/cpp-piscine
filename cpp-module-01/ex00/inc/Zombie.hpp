/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:37:54 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/06/28 15:16:43 by mlanca-c         ###   ########.fr       */
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
		~Zombie( void );

		Zombie( std::string name );

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
