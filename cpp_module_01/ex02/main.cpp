/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:16:42 by ptungbun          #+#    #+#             */
/*   Updated: 2023/11/19 22:00:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string brain = "HI THIS IS BRAIN";
	std::string *stringPtr = &brain;
	std::string stringRef = brain;

	std::cout << &brain << std::endl;
	std::cout << &stringPtr << std::endl;
	std::cout << &stringRef << std::endl;

	std::cout << brain << std::endl;
	std::cout << *stringPtr << std::endl;
	std::cout << stringRef << std::endl;
}
