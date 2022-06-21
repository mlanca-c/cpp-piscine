/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:37:54 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/06/21 16:06:54 by mlanca-c         ###   ########.fr       */
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

# define ERROR(X) std::cout << "cpp-module-01: ex01: " << X << std::endl

/* ************************************************************************** */
/* Classes                                                                    */
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

Zombie* zombieHorde( int N, std::string name );

#endif /* ZOMBIE_HPP */
