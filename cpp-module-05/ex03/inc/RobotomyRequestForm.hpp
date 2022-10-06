/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:50:37 by mlancac           #+#    #+#             */
/*   Updated: 2022/10/06 11:10:56 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

/* ************************************************************************** */
/* Headers                                                                    */
/* ************************************************************************** */

# include <iostream>
# include <exception>
# include <cstdlib>
# include <time.h>
# include "Debug.hpp"
# include "Bureaucrat.hpp"
# include "Form.hpp"

/* ************************************************************************** */
/* Class                                                                      */
/* ************************************************************************** */

class RobotomyRequestForm : public Form {

	public:

		/* Constructors and Destructors */
		~RobotomyRequestForm( void );
		RobotomyRequestForm( RobotomyRequestForm const& src );

		RobotomyRequestForm( std::string const& target );

		/* Operator Overload */
		RobotomyRequestForm&	operator=( RobotomyRequestForm const& rhs );

		/* Getters and Setters */

		/* Other Functions */
		void	execute( Bureaucrat const& b ) const;

	private:

		/* Private Constructors and Destructors */
		RobotomyRequestForm( void );

		/* Other Private Functions */
		void	_execute( void ) const;
	

};

#endif /* ROBOTOMY_REQUEST_FORM_HPP */
