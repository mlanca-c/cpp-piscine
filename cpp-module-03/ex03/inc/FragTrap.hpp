/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 17:17:31 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/29 13:04:47 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

/* ************************************************************************** */
/* Headers                                                                    */
/* ************************************************************************** */

# include <iostream>
# include "ClapTrap.hpp"
# include "Debug.hpp"

/* ************************************************************************** */
/* Class                                                                      */
/* ************************************************************************** */

class FragTrap : virtual public ClapTrap {

	public:

		/* Constructors and Destructors */
		FragTrap( void );
		~FragTrap( void );
		FragTrap( FragTrap const& src );

		FragTrap( std::string name );

		/* Operator Overload */
		FragTrap&	operator=( FragTrap const& rhs );

		/* Other Functions */
		void	attack( const std::string& target );
		void	highFiveGuys( void );

	protected:

		/* Private Attributes */

};

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

std::ostream&	operator<<( std::ostream& os, FragTrap const& rhs );

#endif /* FRAG_TRAP_HPP */
