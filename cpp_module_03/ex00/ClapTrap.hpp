/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:24:35 by ptungbun          #+#    #+#             */
/*   Updated: 2023/12/02 14:03:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iostream>

class ClapTrap
{
	public:

		ClapTrap(void);
		ClapTrap(ClapTrap const &copy);
		ClapTrap(std::string name);
		~ClapTrap(void);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		int		GetHitPoint(void);
		int		GetAttackDamage(void);
		std::string	GetName(void);

		ClapTrap &operator = (const ClapTrap &src);

	private:

		std::string	_name;
		int			_hit_point;
		int			_energy_point;
		int			_attack_damage;
};

#endif
