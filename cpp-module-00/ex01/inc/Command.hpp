/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:35:04 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/06/23 12:12:08 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
# define COMMAND_HPP

/* ************************************************************************** */
/* Headers                                                                    */
/* ************************************************************************** */

# include "PhoneBook.hpp"
# include "Debug.hpp"

# include <iostream>
# include <string>
# include <iomanip>

/* ************************************************************************** */
/* Classes                                                                    */
/* ************************************************************************** */

class	Command {

	public:

		static void	add( PhoneBook& phoneBook );
		static void	search( PhoneBook& phoneBook );

	private:

		static std::string	tag( std::string tag );

};

#endif /* COMMAND_HPP */
