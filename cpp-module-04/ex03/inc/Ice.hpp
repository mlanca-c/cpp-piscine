/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:42:50 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/07/01 15:51:51 by mlanca-c         ###   ########.fr       */
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
# include "ICharacter.hpp"

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

		/* Getters and Setters */

		/* Other Functions */
		AMateria*	clone( void );
		void		use( ICharacter& target );

	private:

		/* Private Attributes */
	

};

#endif /* ICE_HPP */
