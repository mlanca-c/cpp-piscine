/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:51:51 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/04/18 18:28:19 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/* ************************************************************************** */
/* Constructor and Destructor                                                 */
/* ************************************************************************** */

PhoneBook::PhoneBook(void) : _nuContacts(0) {
	// std::cout << "<PhoneBook> Constructor called " << std::endl;
}

PhoneBook::~PhoneBook(void) {
	// std::cout << "<PhoneBook> Destructor called " << std::endl;
}

/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */

int	PhoneBook::getNuContacts(void) {
	if (this->_nuContacts >= 0 && this->_nuContacts <= 8)
		return (this->_nuContacts);
	return (8);
}

Contact	PhoneBook::getContact(int idx) {
	if (idx >= 0 && idx <= this->_nuContacts)
		return (this->_contact[idx]);
	return (this->_contact[0]);
}

void	PhoneBook::addContact(Contact& contact) {
	this->_contact[this->_nuContacts % 8] = contact;
	this->_nuContacts++;
}
