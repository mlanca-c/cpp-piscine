/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:16:30 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/06/14 12:12:40 by mlanca-c         ###   ########.fr       */
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
	std::cout << "|" << std::setfill(' ') << std::setw(10) << std::left << "idx" << "|";
	std::cout << std::setfill(' ') << std::setw(10) << "name" << "|";
	std::cout << std::setfill(' ') << std::setw(10) << "last name" << "|";
	std::cout << std::setfill(' ') << std::setw(10) << "nick" << "|" << std::endl;
	std::cout << std::setfill('-') << std::setw(44) << "|";
	std::cout << "|" << std::endl;

	for (int i = 0; i < phoneBook.getNuContacts(); i++) {
		std::cout << "|" << std::setfill(' ') << std::setw(10) << std::left << i << "|";
		std::cout << std::setfill(' ') << std::setw(10) << phoneBook.getContact(i).getNameFormatted() << "|";
		std::cout << std::setfill(' ') << std::setw(10) << phoneBook.getContact(i).getLastNameFormatted() << "|";
		std::cout << std::setfill(' ') << std::setw(10) << phoneBook.getContact(i).getNicknameFormatted() << "|" << std::endl;
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

	std::cout << "["<< tag << "]: ";
	getline(std::cin, line);
	return (line);
}
