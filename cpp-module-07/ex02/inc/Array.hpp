/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:04:55 by mlancac           #+#    #+#             */
/*   Updated: 2022/10/05 22:44:52 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

/* ************************************************************************** */
/* Headers                                                                    */
/* ************************************************************************** */

# include <iostream>
# include <exception>
# include "Debug.hpp"

/* ************************************************************************** */
/* Template Class                                                             */
/* ************************************************************************** */

template <typename T>
class Array {

	public:

		/* Constructors and Destructors */
		Array( void );
		~Array( void );
		Array( Array const& src );

		Array( unsigned int n );

		/* Operator Overload */
		Array&	operator=( Array const& rhs );
		T&		operator[]( unsigned int n ) throw( std::exception );
		T const&
				operator[]( unsigned int n ) const throw( std::exception );

		/* Getters and Setters */

		/* Other Functions */
		unsigned int	size( void ) const;

		/* Exceptions */
		class IndexOutOfBoundsException : public std::exception {
			public:
				char const*	what( void ) const throw();
		};

	private:

		/* Private Attributes */
		T*				_array;
		unsigned int	_size;
};

/* ************************************************************************** */
/* Template Class Implementation                                              */
/* ************************************************************************** */

template <typename T>
Array<T>::Array( void ) : _array( new T[0] ), _size( 0 ) {
	DEBUG( "<Array> default constructor called" );
}

template <typename T>
Array<T>::~Array( void ) { DEBUG( "<Array> destructor called" ); }

template <typename T>
Array<T>::Array( Array const& src ) {

	*this = src;
	DEBUG( "<Array> copy constructor called" );
}

template <typename T>
Array<T>::Array( unsigned int n ) : _array( new T[n] ), _size( n ) {
	DEBUG( "<Array> constructor called" );
}

template <typename T>
Array<T>&	Array<T>::operator=( Array const& rhs ) {

	this->_size = rhs._size;
	this->_array = new T[this->_size];
	for ( unsigned int i = 0; i < this->_size; i++ ) {
		this->_array[i] = rhs._array[i];
	}

	return ( *this );
}

template <typename T>
T&	Array<T>::operator[]( unsigned int n ) throw( std::exception ) {

	if ( n >= this->_size )
		throw ( Array<int>::IndexOutOfBoundsException() );
	return ( this->_array[n] );
}


template <typename T>
T const&
	Array<T>::operator[]( unsigned int n ) const throw( std::exception ) {

	if ( n >= this->_size )
		throw ( Array<int>::IndexOutOfBoundsException() );
	return ( this->_array[n] );
}

template <typename T>
unsigned int	Array<T>::size( void ) const {
	return ( this->_size );
}

template <typename T>
char const*	Array<T>::IndexOutOfBoundsException::what( void ) const throw() {
	return ( "Array: Exception: index out of bounds"  );
}

#endif /* ARRAY_HPP */
