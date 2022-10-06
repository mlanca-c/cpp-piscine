/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:51:15 by mlancac           #+#    #+#             */
/*   Updated: 2022/07/07 12:24:07 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_FIND_HPP
# define EASY_FIND_HPP

# include <algorithm>

template <typename T>
typename T::iterator	easyfind( T& container, int v ) {

	typename T::iterator	it;

	it = std::find( container.begin(), container.end(), v );
	if ( it == container.end() )
		throw( std::exception() );
	return ( it );
}

#endif /* EASY_FIND_HPP */
