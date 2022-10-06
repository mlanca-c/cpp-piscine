/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:51:00 by mlancac           #+#    #+#             */
/*   Updated: 2022/10/06 11:35:22 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

/* ************************************************************************** */
/* Headers                                                                    */
/* ************************************************************************** */

# include <iostream>
# include <exception>
# include "Debug.hpp"
# include "Bureaucrat.hpp"
# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

/* ************************************************************************** */
/* Class                                                                      */
/* ************************************************************************** */

class Intern {

	public:

		/* Constructors and Destructors */
		Intern( void );
		~Intern( void );
		Intern( Intern const& src );

		/* Operator Overload */
		Intern&	operator=( Intern const& rhs );

		/* Other Functions */
		Form*	makeForm( std::string const& name,
				std::string const& target ) const throw( std::exception );

		/* Exceptions */

		class NoSuchFormException : public std::exception {
			public:
				char const*	what( void ) const throw();
		};

	private:

		/* Private Functions */
		Form*	cloneShrubberyCreationForm( std::string const& target ) const;
		Form*	cloneRobotomyRequestForm( std::string const& target ) const;
		Form*	clonePresidentialPardonForm( std::string const& target ) const;

		/* Private Attributes */
		Form*( Intern::*_formTemplate[3] )( std::string const& ) const;
		std::string	_form[3];

};

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

std::ostream&	operator<<( std::ostream& os, Intern const& rhs );

#endif /* INTERN_HPP */
