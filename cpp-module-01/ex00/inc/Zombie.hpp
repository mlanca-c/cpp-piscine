/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:37:54 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/06/21 15:14:47 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

/* ************************************************************************** */
/* Headers                                                                    */
/* ************************************************************************** */

# include <iostream>

/* ************************************************************************** */
/* Macros                                                                     */
/* ************************************************************************** */

# define ANSI_RED	"\033[31m"
# define ANSI_RESET	"\033[0m"

# if D == 1
#  define DEBUG(X) std::cout << ANSI_RED << X << ANSI_RESET << std::endl
# else
#  define DEBUG(X)
# endif /* D */

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
