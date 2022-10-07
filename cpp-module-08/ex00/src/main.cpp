/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:19:41 by mlancac           #+#    #+#             */
/*   Updated: 2022/10/07 13:13:14 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Debug.hpp"
#include "iostream"
#include "vector"
#include "sstream"
#include "easyfind.hpp"

int	main( int argc, char *argv[] ) {

	( void )argc;
	( void )argv;

	{
		LOG( "test 1: testing with vectors and stdin" );

		std::vector<int>	vec;
		int					len;
		std::string			str;
		
		len = 0;
		while ( 1 ) {

			std::stringstream	ss;
			int					v;

			std::cout << "v[" << len << "]: ";
			getline(std::cin, str);
			if ( str == "" )
				break ;

			ss << str;
			ss >> v;

			vec.push_back( v );
			len++;
		}

		std::cout << "vector: { ";
		for ( int i = 0; i < len; i++ )
			std::cout << vec[i] << ( i == len - 1 ? " ": ", " );
		std::cout << "}" << std::endl;

		while ( 1 ) {

			std::stringstream	ss;
			int					v;

			std::cout << "value to find: ";
			getline(std::cin, str);
			if ( str == "" )
				break ;

			ss << str;
			ss >> v;

			try {
				std::cout << *easyfind( vec, v ) << std::endl;
			}
			catch ( std::exception& e ) { std::cout << e.what() << std::endl; }
		}
	}

	return ( 0 );
}
