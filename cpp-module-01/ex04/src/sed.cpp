/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:13:39 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/06/21 20:02:45 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "debug.hpp"
#include <fstream>

static std::string	sedLine( std::string line, std::string s1, std::string s2 );
static std::string	argvIsForLosers( std::string str );


void	sed( std::string filename, std::string s1, std::string s2 ) {

	std::ifstream	file;
	std::ofstream	replaceFile;
	std::string		line;

	s1 = argvIsForLosers( s1 );
	s2 = argvIsForLosers( s2 );

	file.open( filename.c_str() );
	if ( !file.is_open() ) {
		ERROR( filename << ": failed to open" );
		return ;
	}

	replaceFile.open( (filename + ".replace").c_str() );
	if ( !replaceFile.is_open() ) {
		ERROR( filename << ".replace" << ": failed to create" );
		return ;
	}

	while (getline( file, line )) {
		replaceFile << sedLine( line, s1, s2 ) << std::endl;
	}

	replaceFile.close();
	file.close();
}

static std::string	sedLine( std::string line, std::string s1, std::string s2 ) {

	std::size_t	i;
	std::string	str;

	i = 0;
	while ( 1 ) {
		if (( i = line.find( s1, i )) == std::string::npos )
			break ;
		line = line.erase( i, s1.length() );
		line = line.insert( i, s2 );
		i += s2.length();
	}
	return ( line );
}

static std::string	argvIsForLosers( std::string str ) {

	std::size_t	i;
	char		c;

	i = 0;
	while ( 1 ) {
		if ( (i = str.find( "\\", i )) == std::string::npos )
			break ;

		c = str.at( i + 1 );
		str = str.erase( i, 2 );
		if ( c == 'a' )
			str = str.insert( i, "\a" );
		else if ( c == 'b' )
			str = str.insert( i, "\b" );
		else if ( c == 'f' )
			str = str.insert( i, "\f" );
		else if ( c == 'n' )
			str = str.insert( i, "\n" );
		else if ( c == 'r' )
			str = str.insert( i, "\r" );
		else if ( c == 't' )
			str = str.insert( i, "\t" );
		else if ( c == 'v' )
			str = str.insert( i, "\v" );
	}

	return ( str );
}
