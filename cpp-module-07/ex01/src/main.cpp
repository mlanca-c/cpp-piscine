/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:51:31 by mlancac           #+#    #+#             */
/*   Updated: 2022/10/05 22:38:35 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Debug.hpp"
#include "iter.hpp"
class Awesome
{
	public:
		Awesome( void ) : _n( 42 ) { return; }
		int get( void ) const { return this->_n; }
	private:
		int _n;
};
std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

int	main( int argc, char *argv[] ) {

	( void )argc;
	( void )argv;

	{
		LOG( "test 1: testing print and iter template" );
		int	arr[] = { 1, 2, 3, 4, 5 };

		::iter(arr, 5, &::print<int>);
	}
	{
		LOG( "test 2: testing increment and iter template" );
		LOG( "test 1: testing print and iter template" );
		int	arr[] = { 1, 2, 3, 4, 5 };

		::iter(arr, 5, &::print<int>);
		::iter(arr, 5, &::increment<int>);
		std::cout << "incremented" << std::endl;
		::iter(arr, 5, &::print<int>);
	}

	return ( 0 );
}
