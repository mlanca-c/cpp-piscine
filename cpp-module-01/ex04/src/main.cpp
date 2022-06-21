/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:08:20 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/06/21 19:47:41 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.hpp"
#include <iostream>

int	main( int argc, char *argv[] ) {

	if ( argc != 4 ) {
		ERROR( "wrong number of arguments" );
		return ( 1 );
	}

	sed( argv[1], argv[2], argv[3] );

	return ( 0 );

}
