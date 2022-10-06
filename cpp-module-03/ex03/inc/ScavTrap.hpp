/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 16:44:28 by mlancac           #+#    #+#             */
/*   Updated: 2022/09/22 09:15:59 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

/* ************************************************************************** */
/* Headers                                                                    */
/* ************************************************************************** */

# include <iostream>
# include "ClapTrap.hpp"
# include "Debug.hpp"

/* ************************************************************************** */
/* Classe                                                                     */
/* ************************************************************************** */

class ScavTrap : virtual public ClapTrap {

	public:

		/* Constructors and Destructors */
		ScavTrap( void );
		~ScavTrap( void );
		ScavTrap( ScavTrap const& src );

		ScavTrap( std::string name );

		/* Operator Overload */
		ScavTrap&	operator=( ScavTrap const& rhs );

		/* Getters and Setters */
		bool	getGateMode( void ) const;
		void	setGateMode( bool gateMode );

		/* Other Functions */
		void	attack( const std::string& target );
		void	guardGate( void );

	protected:

		/* Private Attributes */
		bool				_gateMode;
		static int const	_hp;
		static int const	_ep;
		static int const	_ad;

};

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

std::ostream&	operator<<( std::ostream& os, ScavTrap const& rhs );

#endif /* SCAV_TRAP_HPP */
