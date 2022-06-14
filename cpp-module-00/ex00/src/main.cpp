/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:39:50 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/06/14 12:42:09 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string.h>

int	main(int argc, char **argv) {

	if (argc == 1) {
		std::cout << "* LOUD AND UNBERABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}

	for (int i = 0; i < argc; i++) {
		for (int j = 0; j < (int)strlen(argv[i]); j++) {
			std::cout << (char)toupper(argv[i][j]);
		}
		std::cout << " ";
	}
	std::cout << std::endl;
	return (0);
}
