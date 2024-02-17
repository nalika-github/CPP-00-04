/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:03:47 by ptungbun          #+#    #+#             */
/*   Updated: 2024/02/09 21:02:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	try {
		Bureaucrat	A = Bureaucrat("A", 1);
		Bureaucrat	B = Bureaucrat("B", 100);
		Bureaucrat	C = Bureaucrat("C", 150);
		PresidentialPardonForm Pform_A = PresidentialPardonForm("A");
		// PresidentialPardonForm Pform_B = PresidentialPardonForm("B");
		// PresidentialPardonForm Pform_C = PresidentialPardonForm("C");
		RobotomyRequestForm Rform_A = RobotomyRequestForm("A");
		// RobotomyRequestForm Rform_B = RobotomyRequestForm("B");
		RobotomyRequestForm Rform_C = RobotomyRequestForm("C");
		ShrubberyCreationForm Sform_A = ShrubberyCreationForm("A");
		// ShrubberyCreationForm Sform_B = ShrubberyCreationForm("B");
		// ShrubberyCreationForm Sform_C = ShrubberyCreationForm("C");

		std::cout << "Bureaucrat list: " << std::endl;
		std::cout << A << std::endl;
		std::cout << B << std::endl;
		std::cout << C << std::endl;
		std::cout << std::endl;
		std::cout << "Perform PresidentialPardonForm: " << std::endl;
		Pform_A.execute(A);
		// Pform_B.execute(B);
		// Pform_C.execute(C);
		std::cout << "Perform RobotomyRequestForm: " << std::endl;
		Rform_A.execute(A);
		// Rform_B.execute(B);
		// Rform_C.execute(C);
		std::cout << "Perform ShrubberyCreationForm: " << std::endl;
		Sform_A.execute(A);
		// Sform_B.execute(B);
		// Sform_C.execute(C);
	} catch (std::exception &exception) {
		std::cout << exception.what() << std::endl;
	}
	return 0;
}
