/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:03:47 by ptungbun          #+#    #+#             */
/*   Updated: 2024/02/10 00:09:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	std::cout << "======= INTERN =======" << std::endl;
	Intern someRandomIntern;
	AForm* intern_A;
	AForm* intern_b;
	intern_A = someRandomIntern.makeForm("robotomy request", "Bender");
	intern_b = someRandomIntern.makeForm("RobotomyRequest", "Araiva");
	// std::cout << *intern_A << std::endl;
	std::cout << std::endl << *intern_b << std::endl;
	delete intern_b;
	delete intern_A;
	return 0;
}
