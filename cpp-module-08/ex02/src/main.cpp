/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:20:37 by mlancac           #+#    #+#             */
/*   Updated: 2022/10/07 15:44:31 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "Debug.hpp"
#include "MutantStack.hpp"

int	main( int argc, char *argv[] ) {

	( void )argc;
	( void )argv;
	{
		LOG( "test 1" );
		MutantStack<int> m;
		m.push(1);
		m.push(2);
		m.push(3);
		m.push(4);
		m.push(5);

		MutantStack<int>::iterator begin = m.begin();
		MutantStack<int>::iterator end = m.end();

		std::cout << "{ ";
		while ( begin != end ) {
			std::cout << *begin << " ";
			++begin;
		}
		std::cout << "}" << std::endl;
	}

	return ( 0 );
}
