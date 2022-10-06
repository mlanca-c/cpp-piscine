/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:55:58 by mlancac           #+#    #+#             */
/*   Updated: 2022/09/27 09:07:06 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

/* ************************************************************************** */
/* Headers                                                                    */
/* ************************************************************************** */

# include <iostream>
# include "Debug.hpp"

/* ************************************************************************** */
/* Class                                                                      */
/* ************************************************************************** */

class Brain {

	public:

		/* Constructors and Destructors */
		Brain( void );
		~Brain( void );
		Brain( Brain const& src );

		/* Operator Overload */
		Brain&	operator=( Brain const& rhs );

		/* Getters and Setters */
		std::string	getIdea( int idx ) const;
		void		setIdea( std::string idea );
		int			getNuIdeas( void ) const;

		/* Other Functions */
		Brain*	clone( void ) const;

	private:

		/* Private Attributes */
		std::string	_ideas[100];
		int			_nuIdeas;
	

};

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

std::ostream&	operator<<( std::ostream& os, Brain const& rhs );

#endif /* BRAIN_HPP */
