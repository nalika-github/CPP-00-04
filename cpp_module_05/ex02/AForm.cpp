/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:34:38 by ptungbun          #+#    #+#             */
/*   Updated: 2024/02/09 17:31:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute):
name(name), signedStatus(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign > MAX_GRADE)
		throw AForm::GradeTooHighException();
	if (gradeToSign < MIN_GRADE)
		throw AForm::GradeTooLowException();
	std::cout << "Form " << name << " Constructor called" << std::endl;
}

AForm::AForm(const AForm &prototype):
name(prototype.name), signedStatus(prototype.signedStatus),
gradeToSign(prototype.gradeToSign),gradeToExecute(prototype.gradeToExecute)
{
	std::cout << "Form " << name << " Copy Constructor called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "Form " << name << " Deconstructor called" << std::endl;
}

AForm &AForm::operator = (AForm const & rhs)
{
	std::cout << "Assignment operator overload" << std::endl;
	if (this != &rhs)
		signedStatus = rhs.signedStatus;
	return *this;
}

std::ostream& operator << (std::ostream &os, const AForm &form)
{
	os << "Form Name: " << form.name << std::endl
	<< "Signed Status: " << (form.signedStatus ? "Yes" : "No") << std::endl
	<< "Grade to Sign: " << form.gradeToSign << std::endl
	<< "Grade to Execute: " << form.gradeToExecute << std::endl;
	return os;
}

std::string	AForm::getName() const
{
	return name;
}

bool	AForm::isSigned() const
{
	return signedStatus;
}

int	AForm::getGradeToSign() const
{
	return gradeToSign;
}

int	AForm::getGradeToExecute() const
{
	return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= gradeToSign)
		signedStatus = true;
	else
		throw AForm::GradeTooLowException();
}
