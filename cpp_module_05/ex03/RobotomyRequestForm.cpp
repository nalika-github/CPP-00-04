/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:03:40 by ptungbun          #+#    #+#             */
/*   Updated: 2024/02/09 20:54:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):
AForm("RobotomyRequestForm target: " + target, 72, 45), target(target)
{
	std::cout << "RobotomyRequestForm target: " << target
	<< " Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &prototype):
AForm(prototype.getName(), prototype.getGradeToSign(), prototype.getGradeToExecute()), target(prototype.target)
{
	std::cout << "RobotomyRequestForm target: " << target
	<< " Copy Constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm target: " << target
	<< " Deconstructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator = (const RobotomyRequestForm &rhs)
{
	std::cout << "Assignment operator overload" << std::endl;
	if (this != &rhs)
		target = rhs.target;
	return *this;
}

std::ostream& operator << (std::ostream &os, const RobotomyRequestForm &rhs)
{
	os << "RobotomyRequestForm target: " << rhs.target << std::endl;
	return os;
}

std::string	RobotomyRequestForm::getTarget() const
{
	return target;
}

void	RobotomyRequestForm::execute(const Bureaucrat &bureaucrat) const
{

	if (bureaucrat.getGrade() <= getGradeToSign())
	{
		srand(time(NULL));
		if (rand() %2 == 0)
			std::cout << "Whirrrrrrrrrrrrrrrr " << target << "has been robotomized successfully" << std::endl;
		else
			std::cout << "the robotomy failed" << std::endl;
	}
	else
		throw AForm::GradeTooLowException();
}
