/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:23:40 by ptungbun          #+#    #+#             */
/*   Updated: 2023/11/27 20:37:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap nameless;
	ClapTrap Elder_ClapTrap("Elder_ClapTrap");

	nameless.attack(Elder_ClapTrap.GetName());
	Elder_ClapTrap.takeDamage(nameless.GetAttackDamage());
	std::cout << "ClapTrap: " << Elder_ClapTrap.GetName() << " Turn" << std::endl;
	std::cout << "ClapTrap: " << Elder_ClapTrap.GetName() << " Regeneration Passive Skill" << std::endl;
	Elder_ClapTrap.beRepaired(10);
	std::cout << "ClapTrap: " << Elder_ClapTrap.GetName() << " Berserk Skill Active" << std::endl;
	while (nameless.GetHitPoint() > 0)
	{
		Elder_ClapTrap.attack(nameless.GetName());
		nameless.takeDamage(2);
	}
	std::cout << "ClapTrap: " << nameless.GetName() << " Turn" << std::endl;
	nameless.attack(Elder_ClapTrap.GetName());
	nameless.beRepaired(1);
	return (0);
}
