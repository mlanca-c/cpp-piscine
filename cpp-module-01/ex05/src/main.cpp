/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:56:42 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/22 12:41:06 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int	main( int argc, char *argv[] ) {

	Harl	harl = Harl();

	if (argc == 1) {
		ERROR( "wrong number of arguments" );
	}
	harl.complain( argv[1] );
	return (0);
}
