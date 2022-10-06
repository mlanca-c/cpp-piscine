/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:44:33 by mlancac           #+#    #+#             */
/*   Updated: 2022/09/28 10:23:05 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

/* ************************************************************************** */
/* Headers                                                                    */
/* ************************************************************************** */

# include <iostream>
# include <exception>
# include "Debug.hpp"
# include "Bureaucrat.hpp"

/* ************************************************************************** */
/* Class                                                                      */
/* ************************************************************************** */

class Bureaucrat;

class Form {

	public:

		/* Constructors and Destructors */
		Form( void );
		~Form( void );
		Form( Form const& src );

		Form( std::string const& name, int signedGrade,
	   		int executeGrade ) throw( std::exception );

		/* Operator Overload */
		Form&	operator=( Form const& rhs );

		/* Getters and Setters */
		std::string const&	getName( void ) const;
		bool				getIsSigned( void ) const;
		int					getSignedGrade( void ) const;
		int					getExecuteGrade( void ) const;

		/* Other Functions */
		void	beSigned( Bureaucrat& b ) throw( std::exception );

		/* Exceptions */
		class GradeTooHighException : public std::exception {
			public:
				char const*	what( void ) const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				char const*	what( void ) const throw();
		};

		class FormAlreadySignedException: public std::exception {
			public:
				char const*	what( void ) const throw();
		};

	private:

		/* Private Attributes */
		std::string const	_name;
		bool				_isSigned;
		int const			_signedGrade;
		int const			_executeGrade;

};

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

std::ostream&	operator<<( std::ostream& os, Form const& rhs );

#endif /* FORM_HPP */
