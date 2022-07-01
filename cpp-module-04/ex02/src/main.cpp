/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:22:04 by mlancac           #+#    #+#             */
/*   Updated: 2022/07/01 13:18:07 by mlancac          ###   ########.fr       */
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
		LOG( "test 1: Error" );
		AAnimal	*animal = new AAnimal();
		delete animal;
	}

	return ( 0 );
}
