/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:03:49 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/28 15:59:04 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main( int argc, char *argv[] ) {

	( void )argc;
	( void )argv;
	{
		LOG( "test 1: testing Animal class" );
		Animal	a = Animal( "animal" );
		Animal	b( a );
		Animal	c;

		c = b;

		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "c: " << c << std::endl;
	}
	{
		LOG( "test 2: testing Cat class" );
		Animal	a = Cat();
		Animal	b( a );
		Animal	c;

		c = b;

		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "c: " << c << std::endl;
		a.makeSound();
		c.makeSound();
		b.makeSound();
	}
	{
		LOG( "test 3: testing Dog class" );
		Animal	a = Dog();
		Animal	b( a );
		Animal	c;

		c = b;

		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "c: " << c << std::endl;
		a.makeSound();
		c.makeSound();
		b.makeSound();
	}
	{
		LOG( "test 4: testing main from subject" );
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << *i << " " << i->getType() << " " << std::endl;
		std::cout << *j << " " << j->getType() << " " << std::endl;

		i->makeSound();
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete i;
		delete j;
	}
	{
		LOG( "test 5: other tests" );
		const Animal meta = Animal();
		const Animal j = Dog();
		const Animal i = Cat();

		std::cout << i << " " << i.getType() << " " << std::endl;
		std::cout << j << " " << j.getType() << " " << std::endl;

		i.makeSound();
		j.makeSound();
		meta.makeSound();
	}
	{
		const Animal meta = Animal();
		const Dog j = Dog();
		const Cat i = Cat();

		std::cout << i << " " << i.getType() << " " << std::endl;
		std::cout << j << " " << j.getType() << " " << std::endl;

		i.makeSound();
		j.makeSound();
		meta.makeSound();
	}

	return ( 0 );
}
