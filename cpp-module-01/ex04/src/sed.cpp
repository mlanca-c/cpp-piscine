/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:13:39 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/06/21 19:36:46 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "debug.hpp"
#include <fstream>

static std::string	sedLine( std::string line, std::string s1, std::string s2 );

void	sed( std::string filename, std::string s1, std::string s2 ) {

	std::ifstream	file;
	std::ofstream	replaceFile;
	std::string		line;

	file.open( filename );
	if ( !file.is_open() ) {
		ERROR( filename << ": failed to open" );
		return ;
	}

	replaceFile.open( filename + ".replace" );
	if ( !replaceFile.is_open() ) {
		ERROR( filename << ".replace" << ": failed to create" );
		return ;
	}

	while (getline( file, line )) {
		DEBUG(line);
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
		if ( (i = line.find(s1, i)) == std::string::npos )
			break ;
		line = line.erase( i, s1.length() );
		line = line.insert( i, s2 );
		i += s2.length();
	}
	return ( line );
}

