/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:48:22 by ptungbun          #+#    #+#             */
/*   Updated: 2023/11/19 22:34:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon &weapon): _weapon(weapon)
{
	this->_name = name;
}

HumanA::~HumanA()
{
}

void HumanA::attack()
{
  std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
