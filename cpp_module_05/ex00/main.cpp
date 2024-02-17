/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:03:47 by ptungbun          #+#    #+#             */
/*   Updated: 2024/02/06 15:27:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat bureaucrat_A = Bureaucrat("bureaucrat_A", 1);
		Bureaucrat bureaucrat_B = Bureaucrat("bureaucrat_B", 150);
		std::cout << "Bureaucrat info:" << std::endl << bureaucrat_A << std::endl;
		std::cout << "Bureaucrat info:" << std::endl << bureaucrat_B << std::endl;
		bureaucrat_A.decrementGrade();
		bureaucrat_B.incrementGrade();
		std::cout << "Bureaucrat info:" << std::endl << bureaucrat_A << std::endl;
		std::cout << "Bureaucrat info:" << std::endl << bureaucrat_B << std::endl;
		bureaucrat_A.incrementGrade();
		bureaucrat_A.incrementGrade();
	}
	catch (Bureaucrat::GradeTooHighException &exception)
	{
		std::cout << exception.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &exception)
	{
		std::cout << exception.what() << std::endl;
	}
}
