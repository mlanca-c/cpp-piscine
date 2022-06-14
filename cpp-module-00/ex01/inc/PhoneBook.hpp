/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:40:12 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/04/18 18:03:51 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include "Contact.hpp"

class PhoneBook
{

	public:

		/* Constructor and Destructor */
		PhoneBook(void);
		~PhoneBook(void);

		/* Getters and Setters */
		int			getNuContacts(void);
		Contact		getContact(int idx);
		void		addContact(Contact& contact);

	private:

		/* Private Attributes */
		int			_nuContacts;
		Contact		_contact[8];

};

#endif /* PHONEBOOK_HPP */
