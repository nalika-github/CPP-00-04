/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:23:40 by ptungbun          #+#    #+#             */
/*   Updated: 2023/11/28 16:48:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap 	nameless;
	ClapTrap 	Elder_ClapTrap("Elder_ClapTrap");
	ScavTrap	ScavTrap("Common_ScavTrap");
	FragTrap	FragTrap("Common_FragTrap");

	nameless.attack(Elder_ClapTrap.GetName());
	Elder_ClapTrap.takeDamage(nameless.GetAttackDamage());
	std::cout << std::endl << std::endl;
	std::cout << "ClapTrap: " << Elder_ClapTrap.GetName() << " Turn" << std::endl;
	std::cout << "ClapTrap: " << Elder_ClapTrap.GetName() << " Regeneration Passive Skill" << std::endl;
	Elder_ClapTrap.beRepaired(10);
	std::cout << "ClapTrap: " << Elder_ClapTrap.GetName() << " Berserk Skill Active" << std::endl;
	while (nameless.GetHitPoint() > 0)
	{
		Elder_ClapTrap.attack(nameless.GetName());
		nameless.takeDamage(2);
	}
	std::cout << std::endl << std::endl;
	std::cout << "ClapTrap: " << nameless.GetName() << " Turn" << std::endl;
	nameless.attack(Elder_ClapTrap.GetName());
	nameless.beRepaired(1);
	std::cout << std::endl << std::endl;
	std::cout << "ScavTrap: " << ScavTrap.GetName() << " Appear" << std::endl;
	ScavTrap.attack(Elder_ClapTrap.GetName());
	Elder_ClapTrap.takeDamage(5);
	std::cout << std::endl << std::endl;
	std::cout << "ClapTrap: " << Elder_ClapTrap.GetName() << " Turn" << std::endl;
	std::cout << "ClapTrap: " << Elder_ClapTrap.GetName() << " Regeneration Passive Skill" << std::endl;
	Elder_ClapTrap.beRepaired(10);
	Elder_ClapTrap.attack(ScavTrap.GetName());
	ScavTrap.takeDamage(2);
	std::cout << std::endl << std::endl;
	std::cout << "FragTrap: " << FragTrap.GetName() << " Appear" << std::endl;
	FragTrap.attack(Elder_ClapTrap.GetName());
	Elder_ClapTrap.takeDamage(30);
	return (0);
}
