/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:52:07 by mlancac           #+#    #+#             */
/*   Updated: 2022/07/04 13:52:45 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

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

class PresidentialPardonForm : public Form {

	public:

		/* Constructors and Destructors */
		~PresidentialPardonForm( void );
		PresidentialPardonForm( PresidentialPardonForm const& src );

		PresidentialPardonForm( std::string const& target );

		/* Operator Overload */
		PresidentialPardonForm&	operator=( PresidentialPardonForm const& rhs );

		/* Getters and Setters */

		/* Other Functions */
		void	execute( Bureaucrat const& b ) const;

	private:

		/* Private Constructors and Destructors */
		PresidentialPardonForm( void );
	

};

#endif /* PRESIDENTIAL_PARDON_FORM_HPP */

