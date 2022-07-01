/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:22:04 by mlancac           #+#    #+#             */
/*   Updated: 2022/07/01 13:11:42 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Debug.hpp"
#include "Brain.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main( int argc, char *argv[] ) {

	( void )argc;
	( void )argv;

	{
		LOG( "test 1: testing Brain Class" );
		Brain	a;
		Brain	b( a );
		Brain	c;

		b.setIdea( "sit" );
		b.setIdea( "sleep" );
		b.setIdea( "eat" );
		b.setIdea( "bones" );
		b.setIdea( "bones" );

		c = b;

		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "c: " << c << std::endl;


	}
	{
		LOG( "test 2: testing Brain Class in Dog and Cat Classes" );
		Dog const	dog = Dog();
		Cat const	cat = Cat();

		cat.getBrain()->setIdea( "I have a thousand ideas" );
		dog.getBrain()->setIdea( "I have zero ideas" );
		std::cout << dog << std::endl;
		std::cout << cat << std::endl;
	}
	{
		LOG( "test 3: testing with the main from the subject" );
		Animal const*	dog = new Dog();
		Animal const*	cat = new Cat();

		delete dog; // should not create a leak
		delete cat;
	}
	{
		LOG( "test 4: testing with an array of Animals" );
		Animal	animal[10];

		for ( int i = 0; i < 10; i++ ) {
			if ( i % 2 )
				animal[i] = Dog();
			else
				animal[i] = Cat();
		}

		for ( int i = 0; i < 10; i++ )
			std::cout << "[" << i << "]: " << animal[i] << std::endl;
		// delete [] animal;
	}

	return ( 0 );
}
