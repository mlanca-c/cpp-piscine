/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:35:04 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/04/18 18:13:56 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
# define COMMAND_HPP

# include "PhoneBook.hpp"
# include <string>
# include <iostream>
# include <iomanip>

class	Command
{

	public:

		static void	add(PhoneBook& phoneBook);
		static void	search(PhoneBook& phoneBook);

	private:

		static std::string	tag(std::string tag);

};

#endif /* COMMAND_HPP */
