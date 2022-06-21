/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:43:48 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/06/21 16:10:09 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int	main( int argc, char *argv[] ) {

	Zombie*	horde;
	int		n;

	if (argc != 3) {
		ERROR("wrong number of elements");
		return (1);
	}

	n = std::stoi(argv[1]);
	if (!n) {
		ERROR("wrong argument");
		return (1);
	}
	horde = zombieHorde( n, argv[2] );

	for ( int i = 0; i < n; i++ ) {
		horde[i].anounce();
	}

	delete [] horde;
	return ( 0 );
}
