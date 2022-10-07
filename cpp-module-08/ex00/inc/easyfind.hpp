/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:50:33 by mlancac           #+#    #+#             */
/*   Updated: 2022/10/07 13:13:45 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <algorithm>
# include "iostream"

struct	ValueNotFoundException : std::exception {
	char const*	what( void ) const throw() {
		return ( "Exception: value not found" );
	}
};

template <typename T>
typename T::iterator	easyfind( T container, int value ) {

	typename T::iterator	it;

	it = std::find( container.begin(), container.end(), value );
	if ( it == container.end() )
		throw( ::ValueNotFoundException() );
	return ( it );
}
