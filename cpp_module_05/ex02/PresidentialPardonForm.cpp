/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:04:03 by ptungbun          #+#    #+#             */
/*   Updated: 2024/02/09 20:54:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target):
AForm("PresidentialPardonForm target: " + target, 25, 5), target(target)
{
	std::cout << "PresidentialPardonForm target: " << target
	<< " Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &prototype):
AForm(prototype.getName(), prototype.getGradeToSign(), prototype.getGradeToExecute()), target(prototype.target)
{
	std::cout << "PresidentialPardonForm target: " << target
	<< " Copy Constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm target: " << target
	<< " Deconstructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator = (const PresidentialPardonForm &rhs)
{
	std::cout << "Assignment operator overload" << std::endl;
	if (this != &rhs)
		target = rhs.target;
	return *this;
}

std::ostream& operator << (std::ostream &os, const PresidentialPardonForm &rhs)
{
	os << "PresidentialPardonForm target: " << rhs.target << std::endl;
	return os;
}

std::string	PresidentialPardonForm::getTarget() const
{
	return target;
}

void	PresidentialPardonForm::execute(const Bureaucrat &bureaucrat) const
{
	if (bureaucrat.getGrade() <= getGradeToSign())
		std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	else
		throw AForm::GradeTooLowException();
}

