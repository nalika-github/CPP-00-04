/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 21:42:50 by ptungbun          #+#    #+#             */
/*   Updated: 2024/02/10 00:21:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern Constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern Deconstructor called" << std::endl;
}

AForm*	Intern::makeForm(std::string name, std::string target)
{
	AForm	*toReturn;

	std::map<std::string, AForm*> form_lst;
	form_lst["ShrubberyCreation"] = new ShrubberyCreationForm(target);
	form_lst["RobotomyRequest"] = new RobotomyRequestForm(target);
	form_lst["PresidentialPardon"] = new PresidentialPardonForm(target);
	std::map<std::string, AForm*>::iterator i = form_lst.find(name);
	toReturn = NULL;
	if (i != form_lst.end())
	{
		std::cout << "Intern creates" << name << std::endl;
		toReturn = i->second;
	}
	else
		std::cout << "Error: Form " << name << " dose not exist." << std::endl;
	for (std::map<std::string, AForm*>::iterator iter = form_lst.begin(); iter != form_lst.end(); ++iter)
	{
		if (i->second != toReturn)
			delete iter->second;
	}
	return toReturn;
}
