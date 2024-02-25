/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:57:05 by ptungbun          #+#    #+#             */
/*   Updated: 2024/02/24 20:50:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int	main(void)
{
	Array<int>		arrayInt(5);
	Array<char>		arrayChar(5);
	Array<std::string>	arrayString(5);

	for (int i = 0; i < 5; i++)
	{
		arrayInt[i] = i;
		arrayChar[i] = 'a' + i;
		arrayString[i] = "String ";
		arrayString[i] += static_cast<char>(i + '0');
	}
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Int[" << i << "] : " << arrayInt[i] << std::endl;
		std::cout << "Char[" << i << "] : " << arrayChar[i] << std::endl;
		std::cout << "String[" << i << "] : " << arrayString[i] << std::endl;
		std::cout << std::endl;
	}
	return (0);
}
