/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:25:27 by mlancac           #+#    #+#             */
/*   Updated: 2022/07/06 12:50:05 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void	swap( T& a, T& b ) {

  T tmp = a;
  a = b;
  b = tmp;
}

template <typename T>
T	min( T a, T b ) {
	return ( ( a > b ) ? b : a );
}

template <typename T>
T	max( T a, T b ) {
	return ( ( a < b ) ? b : a );
}

#endif /* WHATEVER_HPP */
