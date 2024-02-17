/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:03:47 by ptungbun          #+#    #+#             */
/*   Updated: 2024/02/07 14:14:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
	try {
		Bureaucrat	a = Bureaucrat("A", 1);
		Bureaucrat	b = Bureaucrat("B", 100);
		Form form = Form("form", 50, 50);
		std::cout << form;
		a.signForm(form);
		b.signForm(form);
	} catch (std::exception &exception) {
		std::cout << exception.what() << std::endl;
	}
	return 0;
}
