/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:31:09 by ptungbun          #+#    #+#             */
/*   Updated: 2024/02/24 18:35:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void	print(int & i)
{
	std::cout << i;
}

int		main(void)
{
	int		array[5] = {1, 2, 3, 4, 5};

	iter(array, 5, print);
	std::cout << std::endl;
	return (0);
}
