/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:48:37 by ptungbun          #+#    #+#             */
/*   Updated: 2023/12/01 15:23:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _weapon(0)
{
	std::cout << "HumanB Constructor called" << std::endl;
	this->_name = name;
}

HumanB::~HumanB()
{
	std::cout << "HumanB Destructor called" << std::endl;
}

void HumanB::attack()
{
	if (!_weapon)
	{
		std::cout << _name << " attacks with their hopes and dreams which does not exist." << std::endl;
		return;
	}
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}
