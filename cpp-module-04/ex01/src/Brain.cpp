/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:59:09 by mlancac           #+#    #+#             */
/*   Updated: 2022/09/27 09:38:59 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

Brain::Brain( void ) : _nuIdeas( 0 ) {
	DEBUG( "<Brain> default constructor called" );
}

Brain::~Brain( void ) { DEBUG( "<Brain> destructor called" ); }

Brain::Brain( Brain const& src ) {

	*this = src;
	DEBUG( "<Brain> copy constructor called" );
}

/* ************************************************************************** */
/* Operator Overload                                                          */
/* ************************************************************************** */

Brain&	Brain::operator=( Brain const& rhs ) {

	this->_nuIdeas = rhs._nuIdeas;
	for ( int i = 0; i < this->_nuIdeas; i++ )
		this->_ideas[i] = rhs._ideas[i];
	return ( *this );
}

std::ostream&	operator<<( std::ostream& os, Brain const& rhs ) {

	os << "<Brain>: ";
	for ( int i = 0; i < rhs.getNuIdeas(); i++ ) {
		os << rhs.getIdea( i );
		( i != rhs.getNuIdeas() - 1 ? ( os << ", " ) : ( os << "" ));
	}

	return ( os );
}

/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */

std::string	Brain::getIdea( int idx ) const {

	if ( idx >= 0 && idx < 100 ) return ( this->_ideas[idx] );
	return ( NULL );
}

void	Brain::setIdea( std::string idea ) {

	this->_ideas[ this->_nuIdeas % 100 ] = idea;
	this->_nuIdeas++;
}

int	Brain::getNuIdeas( void ) const { return ( this->_nuIdeas ); }

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

Brain*	Brain::clone( void ) const { return ( new Brain( *this )); }
