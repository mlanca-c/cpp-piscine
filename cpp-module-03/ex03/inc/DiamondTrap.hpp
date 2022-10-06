/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 17:32:51 by mlancac           #+#    #+#             */
/*   Updated: 2022/09/20 13:00:39 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

/* ************************************************************************** */
/* Headers                                                                    */
/* ************************************************************************** */

# include <iostream>
# include "Debug.hpp"
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

/* ************************************************************************** */
/* Class                                                                      */
/* ************************************************************************** */

class DiamondTrap : public FragTrap, public ScavTrap {

	public:

		/* Constructors and Destructors */
		DiamondTrap( void );
		~DiamondTrap( void );
		DiamondTrap( DiamondTrap const& src );

		DiamondTrap( std::string name );

		/* Operator Overload */
		DiamondTrap&	operator=( DiamondTrap const& rhs );

		/* Getters and Setters */
		std::string	getName( void ) const;
		void		setName( std::string name );

		/* Other Functions */
		void	attack( const std::string& target );
		void	whoAmI( void );

	private:

		/* Private Attributes */
		std::string	_name;

};

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

std::ostream&	operator<<( std::ostream& os, DiamondTrap const& rhs );

#endif /* DIAMOND_TRAP_HPP */
