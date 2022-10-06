/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:13:46 by mlancac           #+#    #+#             */
/*   Updated: 2022/07/07 12:28:11 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Debug.hpp"
#include <vector>
#include <list>
#include <algorithm>
#include "easyfind.hpp"

int	main( int argc, char *argv[] ) {

	( void )argc;
	( void )argv;

    int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	LOG( "array = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }" );
    int n = sizeof(arr) / sizeof(arr[0]);
 
	std::vector<int> vect(arr, arr + n);
	{
		LOG( "test 1: finding 5 in array" );
		try {
			std::cout << *easyfind( vect, 5 ) << std::endl;
		}
		catch ( std::exception& e ) { std::cout << e.what() << std::endl; }

		LOG( "test 2: finding 10 in array" );
		try {
			std::cout << *easyfind( vect, 10 ) << std::endl;
		}
		catch ( std::exception& e ) { std::cout << e.what() << std::endl; }
	}
	std::list<int> lst(arr, arr + n);
	{
		LOG( "test 3: finding 0 in list" );
		try {
			std::cout << *easyfind( lst, 0 ) << std::endl;
		}
		catch ( std::exception& e ) { std::cout << e.what() << std::endl; }
		LOG( "test 4: finding -1 in list" );
		try {
			std::cout << *easyfind( lst, -1 ) << std::endl;
		}
		catch ( std::exception& e ) { std::cout << e.what() << std::endl; }
	}

	return ( 0 );
}
