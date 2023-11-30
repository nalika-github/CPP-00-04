/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:16:42 by ptungbun          #+#    #+#             */
/*   Updated: 2023/11/17 18:02:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

int	main(void)
{
	int		n;
	int		i;
	Zombie	*zombies;

	n = 10;
	i = 0;
	zombies = zombieHorde(n, "Common Infected");
	while(i < n)
	{
		zombies[i].announce();
		i++;
	}
	delete [] zombies;
	return (0);
}
