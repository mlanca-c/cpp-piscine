/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:22:04 by mlancac           #+#    #+#             */
/*   Updated: 2022/09/27 09:27:07 by mlanca-c         ###   ########.fr       */
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
		LOG( "test 2: testing Brain Class in Dog Class" );
		Dog a;
		Dog	b( a );
		Dog c;

		b.getBrain()->setIdea( "woof" );
		b.getBrain()->setIdea( "eat" );
		a.getBrain()->setIdea( "play" );

		c = b;

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
	}
	{
		LOG( "test 3: testing Brain Class in Cat Class" );
		Cat a;
		Cat	b( a );
		Cat c;

		b.getBrain()->setIdea( "meow" );
		b.getBrain()->setIdea( "eat" );
		a.getBrain()->setIdea( "sleep" );

		c = b;

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
	}
	{
		LOG( "test 4: testing with the main from the subject" );
		Animal const*	dog = new Dog();
		Animal const*	cat = new Cat();

		delete dog;
		delete cat;
	}
	{
		LOG( "test 5: testing with an array of Animals" );
		int		nu = 3;
		Animal*	animal[nu];

		for ( int i = 0; i < nu; i++ ) {
			if ( i % 2 ) animal[i] = new Dog();
			else animal[i] = new Cat();
		}

		std::cout << "Array of Animals:" << std::endl;
		for ( int i = 0; i < nu; i++ )
			std::cout << "animal[" << i << "]: " << animal[i]->getType() << std::endl;

		for ( int i = 0; i < nu; i++ )
			delete animal[i];
	}

	return ( 0 );
}
