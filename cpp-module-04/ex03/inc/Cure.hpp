/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:51:08 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/07/01 15:52:49 by mlanca-c         ###   ########.fr       */
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
# include "ICharacter.hpp"

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
		AMateria*	clone( void );
		void		use( ICharacter& target );

	private:

		/* Private Attributes */
	

};

#endif /* CURE_HPP */
