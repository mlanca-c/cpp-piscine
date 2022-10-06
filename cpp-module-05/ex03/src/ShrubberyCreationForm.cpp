/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:32:14 by mlancac           #+#    #+#             */
/*   Updated: 2022/10/06 11:11:13 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

ShrubberyCreationForm::ShrubberyCreationForm( void )
	: Form( "ShrubberyCreationForm", "none", 145, 137 ) {

	DEBUG( "ShrubberyCreationForm <" << this->_name
	   << "> default constructor called" );
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {
	DEBUG( "ShrubberyCreationForm <" << this->_name << "> destructor called" );
}

ShrubberyCreationForm::
	ShrubberyCreationForm( ShrubberyCreationForm const& src ) : Form( src ) {

	DEBUG( "ShrubberyCreationForm <" << this->_name
	   << "> copy constructor called" );
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string const& target )
	: Form( "ShrubberyCreationForm", target, 145, 137 ) {

	DEBUG( "ShrubberyCreationForm> " << this->getName()
	   << " constructor called" );
}

/* ************************************************************************** */
/* Operator Overload                                                          */
/* ************************************************************************** */

ShrubberyCreationForm&	ShrubberyCreationForm
	::operator=( ShrubberyCreationForm const& rhs ) {

	Form::operator=( rhs );
	return ( *this );
}

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

void	ShrubberyCreationForm::_execute(void ) const {

	std::string		filename = this->getTarget() + "_shrubbery";
	std::ofstream	file;

	try {
		file.open( filename.c_str() );
	}
	catch ( std::exception& e ) {
		std::cout << e.what() << std::endl;
	}

	file << "           {{ }{\n"
			"          {{}}}{{\n"
			"        {{}}{}}\n"
			"           }}}}{\n"
			"          {{}}{{\n"
			"            | |    \n";
	file.close();
	std::cout << "Created a file "<< filename << "_shrubbery in the working "
			  << "directory, and wrote an ASCII tree inside it." << std::endl;
}
