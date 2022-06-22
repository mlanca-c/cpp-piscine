/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:00:32 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/22 12:49:59 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

/* ************************************************************************** */
/* Headers                                                                    */
/* ************************************************************************** */

# include <iostream>
# include "Debug.hpp"

/* ************************************************************************** */
/* Classes                                                                    */
/* ************************************************************************** */

typedef void ( *fn )();

class Harl {

	public:

		/* Constructors and Destructors */
		Harl( void );
		~Harl( void );

		/* Other Functions */
		void	complain( std::string level );

	private:

		/* Private Functions */
		void	debug();
		void	info();
		void	warning();
		void	error();

		/* Private Attributes */
		void (Harl::*_f[4])( void ) = { &Harl::debug, &Harl::info,
			&Harl::warning, &Harl::error };
		std::string	_level[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

};

#endif /* HARL_HPP */
