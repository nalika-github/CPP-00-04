/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:03:12 by ptungbun          #+#    #+#             */
/*   Updated: 2024/02/09 21:01:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):
AForm("ShrubberyCreationForm target: " + target, 145, 137), target(target)
{
	std::cout << "ShrubberyCreationForm target: " << target
	<< " Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &prototype):
AForm(prototype.getName(), prototype.getGradeToSign(), prototype.getGradeToExecute()), target(prototype.target)
{
	std::cout << "ShrubberyCreationForm target: " << target
	<< " Copy Constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm target: " << target
	<< " Deconstructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator = (const ShrubberyCreationForm &rhs)
{
	std::cout << "Assignment operator overload" << std::endl;
	if (this != &rhs)
		target = rhs.target;
	return *this;
}

std::ostream& operator << (std::ostream &os, const ShrubberyCreationForm &rhs)
{
	os << "ShrubberyCreationForm target: " << rhs.target << std::endl;
	return os;
}

std::string	ShrubberyCreationForm::getTarget() const
{
	return target;
}

void	ShrubberyCreationForm::execute(const Bureaucrat &bureaucrat) const
{
	if (bureaucrat.getGrade() <= getGradeToSign())
	{
		std::string filename = target + "_shrubbery";
		std::ofstream file(filename.c_str());
		if (file.is_open())
		{
			file << tree;
			file.close();
			std::cout << filename + " file created." << std::endl;
		}
		else
			std::cout << "Unable to open file";
	}
	else
		throw AForm::GradeTooLowException();
}
