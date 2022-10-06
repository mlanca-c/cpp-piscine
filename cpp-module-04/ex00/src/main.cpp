/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:22:04 by mlancac           #+#    #+#             */
/*   Updated: 2022/09/27 08:41:47 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Debug.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main( int argc, char *argv[] ) {

	( void )argc;
	( void )argv;

	{
		LOG( "test 1: testing Animal class" );
		Animal	a;
		Animal	b( a );
		Animal	c;

		b = c;

		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "c: " << c << std::endl;
	}
	{
		LOG( "test 2: testing Cat class" );
		Cat	a;
		Cat	b( a );
		Cat	c;

		b = c;

		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "c: " << c << std::endl;
	}
	{
		LOG( "test 3: testing Dog class" );
		Dog	a;
		Dog	b( a );
		Dog	c;

		b = c;

		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "c: " << c << std::endl;
	}
	{
		LOG( "test 4: testing WrongAnimal class" );
		WrongAnimal	a;
		WrongAnimal	b( a );
		WrongAnimal	c;

		b = c;

		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "c: " << c << std::endl;
	}
	{
		LOG( "test 5: testing WrongCat class" );
		WrongCat	a;
		WrongCat	b( a );
		WrongCat	c;

		b = c;

		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "c: " << c << std::endl;
	}
	{
		LOG( "test 6: testing with the main from the subject" );
		Animal const*	meta = new Animal();
		Animal const*	dog = new Dog();
		Animal const*	cat = new Cat();

		std::cout << dog->getType() << std::endl;
		std::cout << cat->getType() << std::endl;
		dog->makeSound();
		cat->makeSound();
		meta->makeSound();

		delete meta;
		delete dog;
		delete cat;
	}
	{
		LOG( "test 7: testing with wrong animal class" );
		WrongAnimal const*	meta = new WrongAnimal();
		WrongAnimal const*	cat = new WrongCat();

		std::cout << cat->getType() << std::endl;
		cat->makeSound();
		meta->makeSound();

		delete meta;
		delete cat;
	}
	{
		LOG( "test 8: testing without pointers to see the diference" );
		Animal	animal = Animal();
		Dog		dog = Dog();
		Cat		cat = Cat();

		animal.makeSound();
		dog.makeSound();
		cat.makeSound();
	}
	{
		LOG( "test 9: testing without pointers to see the diference (WrongClass)" );
		WrongCat	wrongCat = WrongCat();
		WrongAnimal	wrongAnimal = WrongAnimal();

		wrongAnimal.makeSound();
		wrongCat.makeSound();
	}
	return ( 0 );
}
