/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:24:15 by ptungbun          #+#    #+#             */
/*   Updated: 2023/12/02 13:29:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name("nameless ClapTrap"), _hit_point(10), _energy_point(10), _attack_damage(0)
{
	std::cout << "ClapTrap Constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy)
{
	std::cout << "ClapTrap copy Constructor called" << std::endl;
	*this = copy;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hit_point(10), _energy_point(10), _attack_damage(0)
{
	std::cout << "ClapTrap Constructor name set as " << this->_name << " called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Deconstructor for " << this->_name << " called" << std::endl;
}

ClapTrap &ClapTrap::operator = (const ClapTrap &src)
{
	std::cout << "ClapTrap Assignation operator called" << std::endl;
	this->_name = src._name;
	this->_hit_point = src._hit_point;
	this->_energy_point = src._energy_point;
	this->_attack_damage = src._attack_damage;
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_energy_point <= 0)
	{
		std::cout << "ClapTrap: " << this->_name << " out of energy to attack can't attack" << std::endl;
		return ;
	}
	if (this->_hit_point <= 0)
	{
		std::cout << "ClapTrap: " << this->_name << " has died can't do any action" << std::endl;
		return ;
	}
	std::cout << "ClapTrap: " << this->_name << " attacks " << target << std::endl;
	std::cout << this->_name << " <-1 energy point> " << std::endl;
	this->_energy_point--;
	std::cout << this->_name << " remain energy point = " << this->_energy_point << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_hit_point -= amount;
	std::cout << this->_name << " remaining hit point = " << this->_hit_point << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_point <= 0)
	{
		std::cout << this->_name << " out of energy to use repair skill" << std::endl;
		return ;
	}
	if (this->_hit_point <= 0)
	{
		std::cout << this->_name << " has died can't do any action" << std::endl;
		return ;
	}
	this->_energy_point--;
	std::cout << this->_name << " repaired skill active" << std::endl;
	std::cout << this->_name << " be repair = " << amount << std::endl;
	if(this->_hit_point + amount >= 10)
		this->_hit_point = 10;
	else
		this->_hit_point += amount;
	std::cout << this->_name << " hit point status = "<< this->_hit_point << std::endl;
}

int	ClapTrap::GetHitPoint(void)
{
	return(this->_hit_point);
}

int	ClapTrap::GetAttackDamage(void)
{
	return(this->_attack_damage);
}

std::string	ClapTrap::GetName(void)
{
	return(this->_name);
}
