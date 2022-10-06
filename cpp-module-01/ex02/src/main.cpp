/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:23:29 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/06/28 15:46:20 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#define ANSI_GREEN	"\033[32m"
#define ANSI_RESET	"\033[0m"

#define LOG(X)	std::cout << ANSI_GREEN << X << ANSI_RESET <<  std::endl

int	main( int argc, char *argv[] ) {

	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	(void)argc;
	(void)argv;
	{
		LOG( "test 1: memory address" );
		std::cout << "memory address of string:    " << &str << std::endl;
		std::cout << "memory address of stringPTR: " << stringPTR << std::endl;
		std::cout << "memory address of stringREF: " << &stringREF << std::endl;
	}
	{
		LOG( "test 2: value" );
		std::cout << "value of string:             " << str << std::endl;
		std::cout << "value of stringPTR:          " << *stringPTR << std::endl;
		std::cout << "value of stringREF:          " << stringREF << std::endl;
	}
	{
		LOG( "test 4: changing value of string" );
		str = "GOOD MORNING THIS IS BRAIN";
		std::cout << "memory address of string:    " << &str << std::endl;
		std::cout << "memory address of stringPTR: " << stringPTR << std::endl;
		std::cout << "memory address of stringREF: " << &stringREF << std::endl;
		std::cout << "value of string:             " << str << std::endl;
		std::cout << "value of stringPTR:          " << *stringPTR << std::endl;
		std::cout << "value of stringREF:          " << stringREF << std::endl;
	}
	{
		LOG( "test 5: changing value of stringPTR" );
		*stringPTR = "GOOD AFTERNOON THIS IS BRAIN";
		std::cout << "memory address of string:    " << &str << std::endl;
		std::cout << "memory address of stringPTR: " << stringPTR << std::endl;
		std::cout << "memory address of stringREF: " << &stringREF << std::endl;
		std::cout << "value of string:             " << str << std::endl;
		std::cout << "value of stringPTR:          " << *stringPTR << std::endl;
		std::cout << "value of stringREF:          " << stringREF << std::endl;
	}
	{
		LOG( "test 6: changing value of stringREF" );
		stringREF = "GOODBYE THIS WAS BRAIN";
		std::cout << "memory address of string:    " << &str << std::endl;
		std::cout << "memory address of stringPTR: " << stringPTR << std::endl;
		std::cout << "memory address of stringREF: " << &stringREF << std::endl;
		std::cout << "value of string:             " << str << std::endl;
		std::cout << "value of stringPTR:          " << *stringPTR << std::endl;
		std::cout << "value of stringREF:          " << stringREF << std::endl;
	}

	return ( 0 );
}
