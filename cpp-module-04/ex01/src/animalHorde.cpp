/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animalHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:36:27 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/30 17:47:43 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void	animalHorde( int N ) {

	Animal	animal[N];

	if ( N <= 0 ) {
		ERROR( "\"" << N << "\": wrong number" );
		return ;
	}

	for ( int i = 0; i < N; i++ ) {
		if ( i < N / 2 )
			animal[i] = Cat();
		else
			animal[i] = Dog();
	}

	for ( int i = 0; i < N; i++ )
		std::cout << "[" << i << "]: " << animal[i] << std::endl;
}
