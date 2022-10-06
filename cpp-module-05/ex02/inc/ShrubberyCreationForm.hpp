/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:43:11 by mlancac           #+#    #+#             */
/*   Updated: 2022/07/04 13:50:31 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

/* ************************************************************************** */
/* Headers                                                                    */
/* ************************************************************************** */

# include <iostream>
# include <exception>
# include "Debug.hpp"
# include "Bureaucrat.hpp"
# include "Form.hpp"

/* ************************************************************************** */
/* Class                                                                      */
/* ************************************************************************** */

class ShrubberyCreationForm : public Form {

	public:

		/* Constructors and Destructors */
		~ShrubberyCreationForm( void );
		ShrubberyCreationForm( ShrubberyCreationForm const& src );

		ShrubberyCreationForm( std::string const& target );

		/* Operator Overload */
		ShrubberyCreationForm&	operator=( ShrubberyCreationForm const& rhs );

		/* Other Functions */
		void	execute( Bureaucrat const& b ) const;

	private:

		/* Private Constructors and Destructors */
		ShrubberyCreationForm( void );
	
};

#endif /* SHRUBBERY_CREATION_FORM_HPP */
