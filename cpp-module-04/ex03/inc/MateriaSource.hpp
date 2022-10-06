/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 19:42:00 by mlancac           #+#    #+#             */
/*   Updated: 2022/09/27 10:09:42 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

/* ************************************************************************** */
/* Headers                                                                    */
/* ************************************************************************** */

# include <iostream>
# include "Debug.hpp"
# include "IMateriaSource.hpp"

/* ************************************************************************** */
/* Class                                                                      */
/* ************************************************************************** */

class MateriaSource : public IMateriaSource {

	public:

		/* Constructors and Destructors */
		MateriaSource( void );
		~MateriaSource( void );
		MateriaSource( MateriaSource const& src );

		/* Operator Overload */
		MateriaSource&	operator=( MateriaSource const& rhs );

		/* Getters and Setters */
		AMateria*	getInventory( int idx ) const;
		int			getAmount( void ) const;

		/* Other Functions */
		void		learnMateria( AMateria* m );
		AMateria*	createMateria( std::string const& type );

	private:

		/* Private Attributes */
		AMateria*	_inventory[4];
		int			_amount;

};

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

std::ostream&	operator<<( std::ostream& os, MateriaSource const& rhs );

#endif /* MATERIA_SOURCE_HPP */
