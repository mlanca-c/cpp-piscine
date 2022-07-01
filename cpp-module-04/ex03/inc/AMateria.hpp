/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:32:30 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/07/01 16:22:12 by mlanca-c         ###   ########.fr       */
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

class AMateria {

	public:

		/* Constructors and Destructors */
		// AMateria( void );
		~AMateria( void );
		AMateria( AMateria const& src );

		AMateria( std::string const& type );

		/* Operator Overload */
		AMateria&	operator=( AMateria const& rhs );

		/* Getters and Setters */
		std::string const&	getType( void ) const;

		/* Other Functions */
		virtual AMateria*	clone( void ) = 0; // Pure abstract class
		virtual void		use( ICharacter& target );

	protected:

		/* Private Attributes */
		std::string const&	_type;
	

};

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

std::ostream&	operator<<( std::ostream& os, AMateria const& rhs );

#endif /* A_MATERIA_HPP */
