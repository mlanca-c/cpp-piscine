/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:56:42 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/29 10:55:17 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int	main( int argc, char *argv[] ) {

	Harl	harl = Harl();

	if ( argc != 2 ) {
		harl.complain( "DEBUG" );
		return ( 0 );
	}
	harl.complain( argv[1] );
	return (0);
}
