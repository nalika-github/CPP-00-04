/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 01:34:31 by ptungbun          #+#    #+#             */
/*   Updated: 2023/12/02 14:09:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	this->_hit_point = 100;
	this->_energy_point = 100;
	this->_attack_damage = 30;
	std::cout << "FragTrap Constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy)
{
	std::cout << "FragTrap Copy Constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->_hit_point = 100;
	this->_energy_point = 100;
	this->_attack_damage = 30;
	std::cout << "FragTrap Constructor name set as " << this->_name << " called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Deconstructor for " << this->_name << " called" << std::endl;
}

FragTrap &FragTrap::operator = (const FragTrap &src)
{
	std::cout << "FragTrap Assignation operator called" << std::endl;
	this->_name = src._name;
	this->_hit_point = src._hit_point;
	this->_energy_point = src._energy_point;
	this->_attack_damage = src._attack_damage;
	return (*this);
}

void	FragTrap::attack(const std::string &target)
{
	if (this->_energy_point <= 0)
	{
		std::cout << "FragTrap: " << this->_name << " out of energy to attack can't attack" << std::endl;
		return ;
	}
	if (this->_hit_point <= 0)
	{
		std::cout << "FragTrap: " << this->_name << " has died can't do any action" << std::endl;
		return ;
	}
	std::cout << "FragTrap: " << this->_name << " attacks " << target << std::endl;
	std::cout << this->_name << " <-1 energy point> " << std::endl;
	this->_energy_point--;
	std::cout << this->_name << " remain energy point = " << this->_energy_point << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout  << "FragTrap: "<< this->_name << " high fives request" << std::endl;
}

