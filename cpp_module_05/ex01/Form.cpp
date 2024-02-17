/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:34:38 by ptungbun          #+#    #+#             */
/*   Updated: 2024/02/09 18:32:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute):
name(name), signedStatus(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign > MAX_GRADE)
		throw Form::GradeTooHighException();
	if (gradeToSign < MIN_GRADE)
		throw Form::GradeTooLowException();
	std::cout << "Form " << name << " Constructor called" << std::endl;
}

Form::Form(const Form &prototype):
name(prototype.name), signedStatus(prototype.signedStatus),
gradeToSign(prototype.gradeToSign),gradeToExecute(prototype.gradeToExecute)
{
	std::cout << "Form " << name << " Copy Constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form " << name << " Deconstructor called" << std::endl;
}

Form &Form::operator = (Form const & rhs)
{
	std::cout << "Assignment operator overload" << std::endl;
	if (this != &rhs)
		signedStatus = rhs.signedStatus;
	return *this;
}

std::ostream& operator << (std::ostream &os, const Form &form)
{
	os << "Form Name: " << form.name << std::endl
	<< "Signed Status: " << (form.signedStatus ? "Yes" : "No") << std::endl
	<< "Grade to Sign: " << form.gradeToSign << std::endl
	<< "Grade to Execute: " << form.gradeToExecute << std::endl;
	return os;
}

std::string	Form::getName() const
{
	return name;
}

bool	Form::isSigned() const
{
	return signedStatus;
}

int	Form::getGradeToSign() const
{
	return gradeToSign;
}

int	Form::getGradeToExecute() const
{
	return gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= gradeToSign)
		signedStatus = true;
	else
		throw Form::GradeTooLowException();
}
