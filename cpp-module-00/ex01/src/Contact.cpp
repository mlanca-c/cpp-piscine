/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:53:06 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/06/23 10:45:50 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

Contact::Contact( void ) { DEBUG( "<Contact> default constructor called" ); }

Contact::~Contact( void ) { DEBUG( "<Contact> destructor called" ); }

/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */

std::string	Contact::getName( void ) const { return (this->_name); }

std::string	Contact::getLastName( void ) const { return (this->_lastName); }

std::string	Contact::getNickname( void ) const { return (this->_nickname); }

std::string	Contact::getPhone( void ) const { return (this->_phone); }

std::string	Contact::getSecret( void ) const { return (this->_secret); }

void	Contact::setName( std::string name ) { this->_name = name; }

void	Contact::setLastName( std::string lastName ) {
	this->_lastName = lastName;
}

void	Contact::setNickname( std::string nickname ) {
	this->_nickname = nickname;
}

void	Contact::setPhone( std::string phone ) { this->_phone = phone; }

void	Contact::setSecret( std::string secret ) { this->_secret = secret; }

/* ************************************************************************** */
/* Operator's Overload                                                        */
/* ************************************************************************** */

std::ostream&	operator<<( std::ostream& os, Contact const& rhs ) {

	os << std::setfill(' ') << std::setw(20) << "[name]: ";
	os << rhs.getName() << std::endl;
	os << std::setfill(' ') << std::setw(20) << "[last name]: ";
	os << rhs.getLastName() << std::endl;
	os << std::setfill(' ') << std::setw(20) << "[nickname]: ";
	os << rhs.getNickname() << std::endl;
	os << std::setfill(' ') << std::setw(20) << "[phone nu]: ";
	os << rhs.getPhone() << std::endl;
	os << std::setfill(' ') << std::setw(20) << "[secret]: ";
	os << rhs.getSecret() << std::endl;
	return (os);
}

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

std::string	Contact::getNameF( void ) {
	if (this->_name.size() > 10)
		return (this->_name.substr(0, 9).append("."));
	return (this->_name);
}

std::string	Contact::getLastNameF( void ) {
	if (this->_lastName.size() > 10)
		return (this->_lastName.substr(0, 9).append("."));
	return (this->_lastName);
}

std::string	Contact::getNicknameF( void ) {
	if (this->_nickname.size() > 10)
		return (this->_nickname.substr(0, 9).append("."));
	return (this->_nickname);
}
