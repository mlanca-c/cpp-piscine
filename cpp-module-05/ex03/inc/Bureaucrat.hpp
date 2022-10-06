/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 10:31:49 by mlancac           #+#    #+#             */
/*   Updated: 2022/09/28 10:49:06 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

/* ************************************************************************** */
/* Headers                                                                    */
/* ************************************************************************** */

# include <iostream>
# include <exception>
# include "Debug.hpp"
# include "Form.hpp"

/* ************************************************************************** */
/* Class                                                                      */
/* ************************************************************************** */

class Form;

class Bureaucrat {

	public:

		/* Constructors and Destructors */
		~Bureaucrat( void );
		Bureaucrat( Bureaucrat const& src );

		Bureaucrat( std::string const& name, int grade ) throw( std::exception );

		/* Operator Overload */
		Bureaucrat&	operator=( Bureaucrat const& rhs );

		/* Getters and Setters */
		std::string const&	getName( void ) const;
		int					getGrade( void ) const;

		/* Other Functions */
		void	incrementGrade( void ) throw( std::exception ) ;
		void	decrementGrade( void ) throw( std::exception ) ;
		void	signForm( Form& form );
		void	executeForm( Form const& form );

		/* Exceptions */
		class GradeTooHighException : public std::exception {
 			public:
				char const* what( void ) const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				char const* what( void ) const throw();
		};

	protected:

		/* Protected Constructors and Destructors */
		Bureaucrat( void );

	private:

		/* Private Getters and Setters */
		void	setGrade( int grade );

		/* Private Attributes */
		std::string const	_name;
		int					_grade;

};

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

std::ostream&	operator<<( std::ostream& os, Bureaucrat const& rhs );

#endif /* BUREAUCRAT_HPP */
