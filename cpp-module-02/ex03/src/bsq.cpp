/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:11:28 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/06/29 12:01:28 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"
#include "Debug.hpp"

static Fixed	area( Point const a, Point const b, Point const c );

bool	bsp( Point const a, Point const b, Point const c, Point const point) {

 	Fixed a0, a1, a2, a3;

	a0 = area(a, b, c);
	a1 = area(point, a, b);
	a2 = area(point, b, c);
	a3 = area(point, a, c);

	if ( a0 == 0 || a1 == 0 || a2 == 0 || a3 == 0 ) return ( false );

	return ( a1 + a2 + a3 == a0 );
}

static Fixed	area( Point const a, Point const b, Point const c ) {

	Fixed area;

    area = ( a.getX() * ( b.getY() - c.getY() )
		+ b.getX() * ( c.getY() - a.getY() )
        + c.getX() * ( a.getY() - b.getY() )) / 2;

    return ( area < 0 ? ( area * -1 ) : area );
}
