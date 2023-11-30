/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 23:32:27 by ptungbun          #+#    #+#             */
/*   Updated: 2023/11/21 12:54:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

void	Karen::_debug(void)
{
	std::cout << "I love to get extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger.";
	std::cout << " I just love it!" << std::endl;
}

void	Karen::_info(void)
{
	std::cout << "I cannot believe adding extra bacon cost more money.";
	std::cout << " You don’t put enough! If you did I would not have to ask";
	std::cout << " for it!" << std::endl;
}

void	Karen::_warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free.";
	std::cout << " I’ve been coming here for years and you just started ";
	std::cout << "working here last month." << std::endl;
}

void	Karen::_error(void)
{
	std::cout << "This is unacceptable, I want to speak to the manager now.";
	std::cout << std::endl;
}

void	Karen::complain(std::string level)
{
	std::string	levels[4];
	void		(Karen::*ptr_complain[4])(void);
	int			i;

	levels = {DEBUG, INFO, WARNING, ERROR};
	ptr_complain = {&Karen::_debug, &Karen::_info, &Karen::_warning, &Karen::_error};
	i = 0;
	while(i < 4)
	{
		if(level == levels[i])
			return((this->*ptr_complain[i])());
		i++;
	}
}
