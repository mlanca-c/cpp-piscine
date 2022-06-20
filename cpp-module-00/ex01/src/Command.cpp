/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:16:30 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/06/20 21:23:08 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"
#include <sstream>

/* ************************************************************************** */
/* Class Method Implementation                                                */
/* ************************************************************************** */

void	Command::add(PhoneBook& phoneBook) {
	Contact	contact;

	contact.setName(Command::tag("name"));
	if (contact.getName() == "")
	{
		std::cout << "[error]: empty command" << std::endl;
		return ;
	}
	contact.setLastName(Command::tag("last name"));
	if (contact.getLastName() == "")
	{
		std::cout << "[error]: empty command" << std::endl;
		return ;
	}
	contact.setNickname(Command::tag("nickname"));
	if (contact.getNickname() == "")
	{
		std::cout << "[error]: empty command" << std::endl;
		return ;
	}
	contact.setPhone(Command::tag("phone"));
	if (contact.getPhone() == "")
	{
		std::cout << "[error]: empty command" << std::endl;
		return ;
	}
	contact.setSecret(Command::tag("secret"));
	if (contact.getSecret() == "")
	{
		std::cout << "[error]: empty command" << std::endl;
		return ;
	}
	phoneBook.addContact(contact);
}

void	Command::search(PhoneBook& phoneBook) {

	Contact				contact;
	int					idx;
	std::string			str;

	if (phoneBook.getNuContacts() == 0)
	{
		std::cout << "[error]: no contacts" << std::endl;
		return ;
	}
	std::cout << "|" << std::setfill(' ') << std::setw(10) << std::right << "idx" << "|";
	std::cout << std::setfill(' ') << std::right << std::setw(10) << "name" << "|";
	std::cout << std::setfill(' ') << std::right << std::setw(10) << "last name" << "|";
	std::cout << std::setfill(' ') << std::right << std::setw(10) << "nick" << "|" << std::endl;

	std::cout << "|" << std::setfill('-') << std::setw(44) << "|" << std::endl;

	for (int i = 0; i < phoneBook.getNuContacts(); i++) {
		std::cout << "|" << std::setfill(' ') << std::right << std::setw(10) << i << "|";
		std::cout << std::setfill(' ') << std::setw(10) << std::right << phoneBook.getContact(i).getNameFormatted() << "|";
		std::cout << std::setfill(' ') << std::setw(10) << std::right << phoneBook.getContact(i).getLastNameFormatted() << "|";
		std::cout << std::setfill(' ') << std::setw(10) << std::right << phoneBook.getContact(i).getNicknameFormatted() << "|" << std::endl;
	}

	while (1) {
		str = Command::tag("index");
		idx = 0;
		for (int i = 0; str[i] != '\0'; i++) {
			if (!std::isdigit(str[i]))
			{
				idx = 1;
				break ;
			}
		}
		if (!idx)
			idx = std::stoi(str);
		else
			idx = -1;
		if (idx >= 0 && idx < phoneBook.getNuContacts())
			std::cout << phoneBook.getContact(idx);
		else
			break ;
	}
}

std::string	Command::tag(std::string tag) {
	std::string line;

	std::cout << std::setfill(' ') << std::setw(4) << "["<< tag << "]: ";
	getline(std::cin, line);
	return (line);
}
