/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 19:40:09 by mlancac           #+#    #+#             */
/*   Updated: 2022/07/03 19:42:33 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_MATERIA_SOURCE
# define I_MATERIA_SOURCE

/* ************************************************************************** */
/* Headers                                                                    */
/* ************************************************************************** */

# include <iostream>
# include "Debug.hpp"
# include "AMateria.hpp"

/* ************************************************************************** */
/* Class                                                                      */
/* ************************************************************************** */

class IMateriaSource {

	public:

		/* Constructors and Destructors */
		virtual ~IMateriaSource( void ) {}

		/* Other Functions */
		virtual void		learnMateria( AMateria* ) = 0;
		virtual AMateria*	createMateria( std::string const& type ) = 0;

};

#endif /* I_MATERIA_SOURCE */
