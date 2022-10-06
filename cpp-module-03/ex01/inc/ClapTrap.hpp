/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:34:13 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/26 17:30:12 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

/* ************************************************************************** */
/* Headers                                                                    */
/* ************************************************************************** */

# include <iostream>
# include "Debug.hpp"

/* ************************************************************************** */
/* Classe                                                                     */
/* ************************************************************************** */

class ClapTrap {

	public:

		/* Constructors and Destructors */
		ClapTrap( void );
		~ClapTrap( void );
		ClapTrap( ClapTrap const& src );

		ClapTrap( std::string name );

		/* Operator Overload */
		ClapTrap&	operator=( ClapTrap const& rhs );

		/* Getters and Setters */
		std::string		getName( void ) const;
		unsigned int	getHit( void ) const;
		unsigned int	getEnergy( void ) const;
		unsigned int	getAttack( void ) const;

		/* Other Functions */
		void	attack( const std::string& target );
		void	takeDamage( unsigned int amount );
		void	beRepaired( unsigned int amount );

	protected:

		/* Private Getters and Setters */
		void	setName( std::string name );
		void	setHit( unsigned int hit );
		void	setEnergy( unsigned int energy );
		void	setAttack( unsigned int attack );

		/* Private Attributes */
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energy;
		unsigned int	_attack;

};

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

std::ostream&	operator<<( std::ostream& os, ClapTrap const& rhs );

#endif /* CLAP_TRAP_HPP */
