/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:51:31 by mlancac           #+#    #+#             */
/*   Updated: 2022/07/06 13:01:59 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Debug.hpp"
#include "iter.hpp"

int	main( int argc, char *argv[] ) {

	( void )argc;
	( void )argv;

	{
		LOG( "test 1" );
		int	arr[] = { 1, 2, 3, 4, 5 };

		std::cout << "print:" << std::endl;
		::iter<int>( arr, 5, &::print<int> );
		std::cout << "increment:" << std::endl;
		::iter<int>( arr, 5, &::increment<int> );
		::iter<int>( arr, 5, &::print<int> );
	}

	return ( 0 );
}
