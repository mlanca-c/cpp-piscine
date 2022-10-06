/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:51:27 by mlancac           #+#    #+#             */
/*   Updated: 2022/07/06 13:00:57 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void	print( T& arr ) {
	std::cout << arr << std::endl;
}

template <typename T>
void	increment( T& arr ) {
	arr++;
}

template <typename T>
void	iter( T* addr, int len, void( *fn )( T& )) {
	for ( int i = 0; i < len; i++ )
		fn( addr[i] );
}

#endif /* ITER_HPP */
