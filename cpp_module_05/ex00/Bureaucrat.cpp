/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:03:21 by ptungbun          #+#    #+#             */
/*   Updated: 2024/02/07 14:11:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade): name(name), grade(grade)
{
	if (grade > MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	if (grade < MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Bureaucrat " << name << " Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &prototype) : name(prototype.name), grade(prototype.grade)
{
	std::cout << "Bureaucrat " << name << " Copy Constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << name << " Deconstructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator = (Bureaucrat const & rhs)
{
	std::cout << "Assignment operator overload" << std::endl;
	if (this != &rhs)
		grade = rhs.grade;
	return *this;
}

std::ostream& operator << (std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << "Name: " << bureaucrat.name << ", Grade: " << bureaucrat.grade;
	return os;
}

std::string	Bureaucrat::getName() const
{
	return name;
}

int	Bureaucrat::getGrade() const
{
	return grade;
}

void	Bureaucrat::incrementGrade()
{
	if (grade - 1 < MIN_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else
		grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (grade + 1 > MAX_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else
		grade++;
}
