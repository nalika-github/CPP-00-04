/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:16:42 by ptungbun          #+#    #+#             */
/*   Updated: 2023/12/01 22:04:44 by marvin           ###   ########.fr       */
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
	zombies = ZombieHorde(n, "Common Infected");
	while(i < n)
	{
		zombies[i].announce();
		i++;
	}
	delete [] zombies;
	return (0);
}
