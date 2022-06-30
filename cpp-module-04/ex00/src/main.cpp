/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:22:04 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/30 16:50:28 by mlancac          ###   ########.fr       */
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
		LOG( "test 4: testing with the main from the subject" );
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
		LOG( "test 5: testing with wrong animal class" );
		WrongAnimal const*	meta = new WrongAnimal();
		WrongAnimal const*	cat = new WrongCat();

		std::cout << cat->getType() << std::endl;
		cat->makeSound();
		meta->makeSound();

		delete meta;
		delete cat;
	}
	{
		LOG( "test 6: testing without pointers to see the diference" );
		Animal	animal = Animal();
		Dog		dog = Dog();
		Cat		cat = Cat();

		animal.makeSound();
		dog.makeSound();
		cat.makeSound();

		WrongCat	wrongCat = WrongCat();
		WrongAnimal	wrongAnimal = WrongAnimal();

		wrongAnimal.makeSound();
		wrongCat.makeSound();
	}
	return ( 0 );
}
