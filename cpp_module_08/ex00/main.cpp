/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 22:16:20 by ptungbun          #+#    #+#             */
/*   Updated: 2024/03/02 17:33:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <cstdlib>

int main(void)
{
	std::vector<int> v;
	srand(static_cast<unsigned int>(time(NULL)));
	for (int i = 0; i < 10; i++)
		v.push_back(rand() % 20);

	std::cout << "Vector: ";
	for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	try
	{
		std::vector<int>::iterator it = easyfind(v, 5);
		std::cout << "Found 5 at index: " << std::distance(v.begin(), it) << std::endl;
	}
	catch (easyFindException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
