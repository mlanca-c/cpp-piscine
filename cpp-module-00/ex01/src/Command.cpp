/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:16:30 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/06/23 12:27:50 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"
#include <sstream>

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

void	Command::add( PhoneBook& phoneBook ) {

	Contact	contact;

	contact.setName( Command::tag( "name" ));
	if ( contact.getName() == "" ) { ERROR( " empty command" ); }

	contact.setLastName( Command::tag( "last name" ));
	if ( contact.getLastName() == "" ) { ERROR( "empty command" ); }

	contact.setNickname( Command::tag( "nickname" ));
	if ( contact.getNickname() == "" ) { ERROR( "empty command" ); }

	contact.setPhone( Command::tag( "phone" ));
	if ( contact.getPhone() == "" ) { ERROR( "empty command" ); }

	contact.setSecret( Command::tag( "secret" ));
	if ( contact.getSecret() == "" ) { ERROR( "empty command" ); }

	phoneBook.addContact( contact );
}

void	Command::search( PhoneBook& phoneBook ) {

	Contact		contact;
	int			idx;
	std::string	str;

	if ( phoneBook.getNuContacts() == 0 ) { ERROR( "no contacts" ); }

	std::cout << "|" << std::setfill( ' ' ) << std::setw( 10 ) << std::right
			  << "idx" << "|";
	std::cout << std::setfill( ' ' ) << std::right << std::setw( 10 )
			  << "name" << "|";
	std::cout << std::setfill( ' ' ) << std::right << std::setw( 10 )
			  << "last name" << "|";
	std::cout << std::setfill( ' ' ) << std::right << std::setw( 10 )
			  << "nick" << "|" << std::endl;
	std::cout << "|" << std::setfill('-') << std::setw( 44 ) << "|"
			  << std::endl;

	for ( int i = 0; i < phoneBook.getNuContacts(); i++ ) {

		std::cout << "|" << std::setfill(' ') << std::right 
				  << std::setw( 10 ) << i << "|";
		std::cout << std::setfill( ' ' ) << std::setw( 10 ) << std::right
				  << phoneBook.getContact(i).getNameF() << "|";
		std::cout << std::setfill( ' ' ) << std::setw( 10 ) << std::right
				  << phoneBook.getContact(i).getLastNameF() << "|";
		std::cout << std::setfill( ' ' ) << std::setw( 10 ) << std::right
				  << phoneBook.getContact(i).getNicknameF()
				  << "|" << std::endl;
	}

	while ( 1 ) {
		str = Command::tag( "index" );
		idx = 0;

		for ( int i = 0; str[i] != '\0'; i++ ) {
			if ( !std::isdigit( str[i] )) {
				idx = 1;
				break ;
			}
		}

		if ( !idx && str[0] )
			idx = std::stoi( str );
		else
			idx = -1;

		if ( idx >= 0 && idx < phoneBook.getNuContacts() )
			std::cout << phoneBook.getContact( idx );
		else
			break ;
	}
}

std::string	Command::tag( std::string tag ) {

	std::string line;

	std::cout << std::setfill( ' ' ) << std::setw( 4 ) << "["<< tag << "]: ";
	getline( std::cin, line );

	return ( line );
}
