/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:43:42 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/06/23 12:13:03 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

/* ************************************************************************** */
/* Headers                                                                    */
/* ************************************************************************** */

# include "Debug.hpp"
# include <string>
# include <iomanip>
# include <iostream>

/* ************************************************************************** */
/* Classes                                                                    */
/* ************************************************************************** */

class Contact {

	public:

		/* Constructor and Destructor */
		Contact( void );
		~Contact( void );

		/* Getters and Setters */
		std::string	getName( void ) const;
		std::string	getLastName( void ) const;
		std::string	getNickname( void ) const;
		std::string	getPhone( void ) const;
		std::string	getSecret( void ) const;

		void	setName( std::string name );
		void	setLastName( std::string lastName );
		void	setNickname( std::string nickname );
		void	setPhone( std::string phone );
		void	setSecret( std::string secret );

		/* Other Functions */
		std::string	getNameF( void );
		std::string	getLastNameF( void );
		std::string	getNicknameF( void );

	private:

		/* Private Attributes */
		std::string	_name;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phone;
		std::string	_secret;

};

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

std::ostream&	operator<<(std::ostream& os, Contact const& rhs);

#endif /* CONTACT_HPP */
