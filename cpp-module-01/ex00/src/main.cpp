/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:36:14 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/06/21 15:12:18 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int	main(void) {
	Zombie	z = Zombie( "z" );
	Zombie*	newZ;

	newZ = newZombie( "new z" );
	newZ->anounce();
	delete newZ;

	z.anounce();

	randomChump( "random z" );

	return (0);
}
