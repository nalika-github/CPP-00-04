/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:48:22 by ptungbun          #+#    #+#             */
/*   Updated: 2023/12/01 15:23:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon &weapon): _weapon(weapon)
{
	std::cout << "HumanA Constructor called" << std::endl;
	this->_name = name;
}

HumanA::~HumanA()
{
	std::cout << "HumanA Destructor called" << std::endl;
}

void HumanA::attack()
{
  std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
