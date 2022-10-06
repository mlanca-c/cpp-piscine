/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:48:59 by mlancac           #+#    #+#             */
/*   Updated: 2022/07/03 19:16:05 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

/* ************************************************************************** */
/* Headers                                                                    */
/* ************************************************************************** */

# include <iostream>
# include "Debug.hpp"
# include "AMateria.hpp"

/* ************************************************************************** */
/* Class                                                                      */
/* ************************************************************************** */

class Cure : public AMateria {

	public:

		/* Constructors and Destructors */
		Cure( void );
		~Cure( void );
		Cure( Cure const& src );

		/* Operator Overload */
		Cure&	operator=( Cure const& rhs );

		/* Getters and Setters */

		/* Other Functions */
		Cure*	clone( void ) const;
		void	use( ICharacter& target );

	private:

		/* Private Attributes */
	

};

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

std::ostream&	operator<<( std::ostream& os, Cure const& rhs );

#endif /* CURE_HPP */
