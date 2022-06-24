/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:11:28 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/06/24 15:39:52 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"
#include "Debug.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point) {

	Fixed	areaABC;
	Fixed	areaABP;
	Fixed	areaACP;
	Fixed	areaBCP;

	areaABC = Point::area( a, b, c );
	areaABP = Point::area( a, b, point );
	areaACP = Point::area( a, c, point );
	areaBCP = Point::area( b, c, point );

	std::cout << "area( a, b, c ): " << areaABC << std::endl;
	std::cout << "area( a, b, point ): " << areaABP << std::endl;
	std::cout << "area( a, c, point ): " << areaACP << std::endl;
	std::cout << "area( b, c, point ): " << areaBCP << std::endl;
	std::cout << "sum: " << areaABC + areaABP + areaACP + areaBCP << std::endl;

	if ( areaABC == 0 || areaABP == 0 || areaACP == 0 || areaBCP == 0 )
		return (false);
	return ( areaABC < ( areaABP + areaACP + areaBCP ) );
}
