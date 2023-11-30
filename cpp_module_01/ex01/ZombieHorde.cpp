/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:22:50 by ptungbun          #+#    #+#             */
/*   Updated: 2023/11/19 21:58:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde( int N, std::string name)
{
	int		i;
	Zombie *zombies;

	zombies = new Zombie[N];
	i = 0;
	while (i < N)
	{
		zombies[i].setName(name);
		i++;
	}
	return (zombies);
}
