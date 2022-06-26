/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:56:42 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/26 15:06:19 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int	main( int argc, char *argv[] ) {

	Harl	harl = Harl();

	{
		LOG( "test 1: basic test" );
		harl.complain( "DEBUG" );
	}

	if ( argc != 2 ) {
		return ( 0 );
	}
	{
		LOG( "test 2: user testing" );
		harl.complain( argv[1] );
	}
	return (0);
}
