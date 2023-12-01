/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:02:32 by ptungbun          #+#    #+#             */
/*   Updated: 2023/11/30 19:49:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	std::string		line;
	PhoneBook		pb;

	while(true)
	{
		pb.getline_cmd_display();
		if (!std::getline(std::cin, line))
			break ;
		if (line.compare("ADD") == 0)
			pb.excuse_add();
		if (line.compare("SEARCH") == 0)
			pb.excuse_search();
		if (line.compare("EXIT") == 0)
			break ;
		std::cin.clear();
	}
	std::cin.clear();
	return (0);
}
