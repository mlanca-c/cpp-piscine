/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:01:35 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/06/21 18:01:39 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main( int argc, char *argv[] ) {

	(void)argc;
	(void)argv;
	{
		LOG( "test 1: testing weapon class" );
		Weapon		club = Weapon( "crude spiked club" );
		std::string	str;

		std::cout << "<Weapon>: " << club.getType() << std::endl;
		club.setType("some other type of club");
		std::cout << "<Weapon>: " << club.getType() << std::endl;

		str = club.getType();
		std::cout << "<str>: " << str << std::endl;
		str = "crude spiked club";
		std::cout << "<str>: " << str << std::endl;
		std::cout << "<Weapon>: " << club.getType() << std::endl;
	}
	{
		LOG( "test 2: testing HumanA" );
		Weapon	club = Weapon( "crude spiked club" );
		HumanA	bob("Bob", club);

		bob.attack();
		club.setType( "some other type of club" );
		bob.attack();
	}
	{
		LOG( "test 3: testing HumanB" );
		Weapon	club = Weapon( "crude spiked club" );
		HumanB	jim( "Jim" );

		jim.setWeapon( club );
		jim.attack();
		club.setType( "some other type of club" );
		jim.attack();
	}
	return ( 0 );
}
