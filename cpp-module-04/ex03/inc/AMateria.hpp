/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 22:03:53 by mlancac           #+#    #+#             */
/*   Updated: 2022/09/27 09:57:27 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_MATERIA_HPP
# define A_MATERIA_HPP

/* ************************************************************************** */
/* Headers                                                                    */
/* ************************************************************************** */

# include <iostream>
# include "Debug.hpp"
# include "ICharacter.hpp"

/* ************************************************************************** */
/* Class                                                                      */
/* ************************************************************************** */

class ICharacter;

class AMateria {

	public:

		/* Constructors and Destructors */
		AMateria( void );
		virtual ~AMateria( void );
		AMateria( AMateria const& src );

		AMateria( std::string const& type );

		/* Operator Overload */
		AMateria&	operator=( AMateria const& rhs );

		/* Getters and Setters */
		std::string const&	getType( void ) const;

		/* Other Functions */
		virtual AMateria*	clone( void ) const = 0;
		virtual void		use( ICharacter& target );

	protected:

		/* Private Attributes */
		std::string const	_type;
	
};

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

std::ostream&	operator<<( std::ostream& os, AMateria const& rhs );

#endif /* A_MATERIA_HPP */
