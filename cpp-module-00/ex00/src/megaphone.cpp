/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:39:50 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/10/06 11:43:39 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>

int	main(int argc, char **argv) {

	std::string	str;

	if ( argc == 1 ) {
		std::cout << "* LOUD AND UNBERABLE FEEDBACK NOISE *" << std::endl;
		return ( 0 );
	}

	for ( int i = 1; i < argc; i++ ) {
		str = std::string( argv[i] );

		for ( int j = 0; j < static_cast<int>( str.length() ); j++ )
			std::cout << static_cast<char>( std::toupper( str[j] ));
		std::cout << " ";
	}
	std::cout << std::endl;

	return ( 0 );
}