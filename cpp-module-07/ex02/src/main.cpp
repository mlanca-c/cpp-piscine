/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:19:39 by mlancac           #+#    #+#             */
/*   Updated: 2022/10/05 22:43:01 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Array.hpp>
#include <cstdlib>
#include <time.h>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}

// #include <iostream>
// #include "Debug.hpp"
// #include "Array.hpp"
//
// int	main( int argc, char *argv[] ) {
//
// 	( void )argc;
// 	( void )argv;
//
// 	{
// 		LOG( "test 1: testing Array Class Template" );
// 		Array<std::string>		a1( 1 );
//
// 		std::cout << "a1.size() = " << a1.size() << std::endl;
// 		a1[0] = "Hello";
// 		for ( unsigned int i = 0; i < a1.size(); i++ ) {
// 			std::cout << "a1[" << i << "] = " << a1[i] << std::endl;
// 		}
//
// 		Array<int>		a2( 5 );
// 		std::cout << "a2.size() = " << a2.size() << std::endl;
// 		for ( unsigned int i = 0; i < a2.size(); i++ ) {
// 			a2[i] = i;
// 		}
// 		for ( unsigned int i = 0; i < a2.size(); i++ ) {
// 			std::cout << "a2[" << i << "] = " << a2[i] << std::endl;
// 		}
//
// 		try {
// 			a2[5] = 5;
// 		}
// 		catch ( std::exception& e ) { std::cout << e.what() << std::endl; }
// 	}
//
// 	return ( 0 );
// }
