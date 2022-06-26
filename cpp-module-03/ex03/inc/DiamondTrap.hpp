/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 17:32:51 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/26 17:37:22 by mlancac          ###   ########.fr       */
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

class DiamondTrap {

	public:

		/* Constructors and Destructors */

		/* Operator Overload */

		/* Other Functions */

	private:

		/* Private Attributes */

};

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

std::ostream&	operator<<( std::ostream& os, DiamondTrap const& rhs )const;

#endif /* DIAMOND_TRAP_HPP */
