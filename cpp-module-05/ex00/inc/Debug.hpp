#ifndef DEBUG_HPP
# define DEBUG_HPP

/* ************************************************************************** */
/* Headers                                                                    */
/* ************************************************************************** */

# include <iostream>

/* ************************************************************************** */
/* Macros                                                                     */
/* ************************************************************************** */

/* Ansi Colors */
# define ANSI_RESET		"\033[0m"
# define ANSI_RED		"\033[31m"
# define ANSI_GREEN		"\033[32m"
# define ANSI_YELLOW	"\033[33m"

/* Message Templates */
# if D == 1
#  define DEBUG(X)	std::cout << ANSI_RED << X << ANSI_RESET << std::endl
#  define LOG(X)	std::cout << ANSI_GREEN << X << ANSI_RESET << std::endl
# else
#  define DEBUG(X)
#  define LOG(X)	std::cout << X << std::endl
# endif /* D */

# define ERROR(X)	std::cout << ANSI_RED << "error: " << ANSI_RESET << X\
	<< std::endl

#endif /* DEBUG_HPP */
