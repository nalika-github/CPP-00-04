/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 01:34:31 by ptungbun          #+#    #+#             */
/*   Updated: 2023/12/02 14:07:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	this->_hit_point = 100;
	this->_energy_point = 50;
	this->_attack_damage = 20;
	std::cout << "ScavTrap Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy)
{
	std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->_hit_point = 100;
	this->_energy_point = 50;
	this->_attack_damage = 20;
	std::cout << "ScavTrap Constructor name set as " << this->_name << " called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Deconstructor for " << this->_name << " called" << std::endl;
}

ScavTrap &ScavTrap::operator = (const ScavTrap &src)
{
	std::cout << "ScavTrap Assignation operator called" << std::endl;
	this->_name = src._name;
	this->_hit_point = src._hit_point;
	this->_energy_point = src._energy_point;
	this->_attack_damage = src._attack_damage;
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_energy_point <= 0)
	{
		std::cout << "ScavTrap: " << this->_name << " out of energy to attack can't attack" << std::endl;
		return ;
	}
	if (this->_hit_point <= 0)
	{
		std::cout << "ScavTrap: " << this->_name << " has died can't do any action" << std::endl;
		return ;
	}
	std::cout << "ScavTrap: " << this->_name << " attacks " << target << std::endl;
	std::cout << this->_name << " <-1 energy point> " << std::endl;
	this->_energy_point--;
	std::cout << this->_name << " remain energy point = " << this->_energy_point << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout  << "ScavTrap: "<< this->_name << " ScavTrap is now in Gate keeper mode" << std::endl;
}

