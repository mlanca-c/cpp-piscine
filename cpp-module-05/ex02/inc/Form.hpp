/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:44:33 by mlancac           #+#    #+#             */
/*   Updated: 2022/07/04 13:46:29 by mlancac          ###   ########.fr       */
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
		virtual ~Form( void ) {};
		Form( Form const& src );

		Form( std::string const& name, std::string const& target, bool isSigned,
	   		int signedGrade, int executeGrade ) throw( std::exception );

		/* Operator Overload */
		Form&	operator=( Form const& rhs );

		/* Getters and Setters */
		std::string const&	getName( void ) const;
		std::string const&	getTarget( void ) const;
		bool				getIsSigned( void ) const;
		int					getSignedGrade( void ) const;
		int					getExecuteGrade( void ) const;

		/* Other Functions */
		void			beSigned( Bureaucrat& b ) throw( std::exception );
		virtual void	execute( Bureaucrat const& b ) const = 0;

		/* Exceptions */
		class GradeTooHighException : public std::exception {
			public:
				 char const*	what( void ) const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				char const*	what( void ) const throw();
		};

		class FormNotSignedException : public std::exception {
			public:
				char const*	what( void ) const throw();
		};

	protected:

		/* Protected Functions */
		void	_gradeValid( void ) const throw( std::exception );

	private:

		/* Private Constructors and Destructors */
		Form( void );

		/* Private Attributes */
		std::string const	_name;
		std::string const	_target;
		bool				_isSigned;
		int const			_signedGrade;
		int const			_executeGrade;
	

};

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

std::ostream&	operator<<( std::ostream& os, Form const& rhs );

#endif /* FORM_HPP */