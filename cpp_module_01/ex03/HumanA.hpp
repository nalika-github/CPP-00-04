/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:48:48 by ptungbun          #+#    #+#             */
/*   Updated: 2023/12/01 15:12:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_H
# define HUMAN_A_H
# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanA
{

public:
	HumanA(const std::string& name, Weapon &weapon);
	~HumanA(void);

	void	attack(void);

private:
	std::string	_name;
	Weapon		&_weapon;

};

#endif
