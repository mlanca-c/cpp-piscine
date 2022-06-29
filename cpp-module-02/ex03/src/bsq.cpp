/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:11:28 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/06/25 14:20:58 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"
#include "Debug.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point) {

	Point	v1, v2, v3;
	Fixed	f1, f2, fx, fy;

	v1 = b - a;
	v2 = c - a;
	v3 = point - a;

	f1 = v1 * v1;
	f2 = v2 * v2;

	fx = v3 * v1 / f1;
	fy = v3 * v2 / f2;

	return ( fx > 0 && fy > 0 && fx + fy < 1 );
}
