/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:31:09 by ptungbun          #+#    #+#             */
/*   Updated: 2024/02/25 19:52:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template<typename Type> void print(Type& x)
{
	std::cout << x << std::endl;
}


int	main(void)
{
	int	array1[3] = {1, 2, 3};
	unsigned int	array2[3] = {4, 5, 6};
	iter(array1, 3, print<int>);
	iter(array2, 3, print<unsigned int>);
	return (0);
}
