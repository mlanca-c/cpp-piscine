/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:53:15 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/06/21 17:25:32 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

/* ************************************************************************** */
/* Headers                                                                    */
/* ************************************************************************** */

# include <iostream>

/* ************************************************************************** */
/* Macros                                                                     */
/* ************************************************************************** */

# define ANSI_RED	"\033[31m"
# define ANSI_GREEN	"\033[32m"
# define ANSI_RESET	"\033[0m"

# if D == 1
#  define DEBUG(X)	std::cout << ANSI_RED << X << ANSI_RESET << std::endl
# else
#  define DEBUG(X)
# endif /* D */

# define ERROR(X)	std::cout << "cpp-module-01: ex01: " << X << std::endl
# define LOG(X)		std::cout << ANSI_GREEN << X << ANSI_RESET << std::endl

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
