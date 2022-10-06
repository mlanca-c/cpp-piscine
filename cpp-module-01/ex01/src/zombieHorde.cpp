/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:43:27 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/06/26 14:47:59 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {

	if ( N <= 0 ) {
		ERROR( "\"" << N << "\": wrong argument" );
		return ( NULL );
	}

	Zombie*	z = new Zombie[ N ];

	for ( int i = 0; i < N; i++ ) {
		z[i].setName( name );
	}

	return ( z );
}
