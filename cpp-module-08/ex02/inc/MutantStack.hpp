/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:15:25 by mlancac           #+#    #+#             */
/*   Updated: 2022/10/07 15:47:26 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

/* ************************************************************************** */
/* Headers                                                                    */
/* ************************************************************************** */

# include <iostream>
# include <stack>
# include "Debug.hpp"

/* ************************************************************************** */
/* Class Template                                                             */
/* ************************************************************************** */

template <typename T>
class MutantStack : public std::stack<T> {

	public:

		typedef typename std::stack<T>::container_type::iterator	iterator;

		/* Constructors and Destructors */
		MutantStack( void );
		~MutantStack( void );
		MutantStack( MutantStack const& src );

		/* Operator Overload */
		MutantStack&	operator=( MutantStack const& rhs );

		/* Other Functions */
		iterator	begin( void );
		iterator	end( void );

};

/* ************************************************************************** */
/* Template Class Implementation                                              */
/* ************************************************************************** */

template <typename T>
MutantStack<T>::MutantStack( void ) {
	DEBUG( "MutantStack default constructor called" );
}

template <typename T>
MutantStack<T>::~MutantStack( void ) {
	DEBUG( "MutantStack destructor called" );
}

template <typename T>
MutantStack<T>::MutantStack( MutantStack const& src ) {

	*this = src;
	DEBUG( "MutantStack copy constructor called" );
}

template <typename T>
MutantStack<T>&	MutantStack<T>::operator=( MutantStack const& rhs ) {

	std::stack<int>::operator=( rhs );
	return ( *this );
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin() {
	return ( this->c.begin() );
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end() {
	return ( this->c.end() );
}

#endif /* MUTANT_STACK_HPP */
