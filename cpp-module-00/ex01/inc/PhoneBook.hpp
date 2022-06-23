/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:40:12 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/06/23 12:21:31 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

/* ************************************************************************** */
/* Headers                                                                    */
/* ************************************************************************** */

# include <string>
# include "Debug.hpp"
# include "Contact.hpp"

/* ************************************************************************** */
/* Classes                                                                    */
/* ************************************************************************** */

class PhoneBook {

	public:

		/* Constructors and Destructors */
		PhoneBook( void );
		~PhoneBook( void );

		/* Getters and Setters */
		int			getNuContacts( void );
		Contact		getContact( int idx );

		/* Other Functions */
		void		addContact( Contact& contact );

	private:

		/* Private Attributes */
		int			_nuContacts;
		Contact		_contact[8];

};

#endif /* PHONEBOOK_HPP */
