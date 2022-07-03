/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 22:10:08 by mlancac           #+#    #+#             */
/*   Updated: 2022/07/03 19:14:34 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

/* ************************************************************************** */
/* Headers                                                                    */
/* ************************************************************************** */

# include <iostream>
# include "Debug.hpp"
# include "AMateria.hpp"

/* ************************************************************************** */
/* Class                                                                      */
/* ************************************************************************** */

class Ice : public AMateria {

	public:

		/* Constructors and Destructors */
		Ice( void );
		~Ice( void );
		Ice( Ice const& src );

		/* Operator Overload */
		Ice&	operator=( Ice const& rhs );

		/* Other Functions */
		Ice*	clone( void ) const;
		void		use( ICharacter& target );

	private:

		/* Private Attributes */
	

};

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

std::ostream&	operator<<( std::ostream& os, Ice const& rhs );

#endif /* ICE_HPP */
