/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 16:44:28 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/26 17:18:57 by mlancac          ###   ########.fr       */
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
/* Class                                                                      */
/* ************************************************************************** */

class ScavTrap : public ClapTrap {

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
		void	guardGate( void );

	private:

		/* Private Attributes */
		bool	_gateMode;

};

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

std::ostream&	operator<<( std::ostream& os, ScavTrap const& rhs );

#endif /* SCAV_TRAP_HPP */
