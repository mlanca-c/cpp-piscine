/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:29:36 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/04/18 17:20:06 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Command.hpp"
#include "PhoneBook.hpp"

static void cli(void);

int	main(void)
{
	cli();
	return (0);
}

static void cli(void)
{
	std::string command;
	PhoneBook	phoneBook;

	while (1)
	{
		std::cout << "[command]: ";
		getline(std::cin, command);
		if (command == "ADD")
			Command::add(phoneBook);
		else if (command == "SEARCH")
			Command::search(phoneBook);
		else if (command == "EXIT")
			break ;
		else
			ERROR( "could not find command"  );
	}
}
