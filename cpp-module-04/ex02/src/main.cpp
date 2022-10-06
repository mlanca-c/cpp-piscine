/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:22:04 by mlancac           #+#    #+#             */
/*   Updated: 2022/09/27 09:37:13 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Debug.hpp"
#include "Brain.hpp"
#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main( int argc, char *argv[] ) {

	( void )argc;
	( void )argv;
	{
		LOG( "test 1: Testing Classes Dog and Cat" );
		AAnimal*	dog = new Dog();
		AAnimal*	cat = new Cat();

		cat->getBrain()->setIdea( "eat" );
		cat->getBrain()->setIdea( "play" );
		cat->getBrain()->setIdea( "sleep" );
		std::cout << *cat << std::endl;
		cat->makeSound();

		dog->getBrain()->setIdea( "eat" );
		dog->getBrain()->setIdea( "play" );
		dog->getBrain()->setIdea( "be a good boy" );
		std::cout << *dog << std::endl;
		dog->makeSound();

		delete dog;
		delete cat;
	}
	// {
	// 	LOG( "test 2: Error" );
	// 	AAnimal	*animal = new AAnimal();
	// 	delete animal;
	// }

	return ( 0 );
}
