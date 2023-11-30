/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:23:40 by ptungbun          #+#    #+#             */
/*   Updated: 2023/11/30 14:33:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
	const Animal	*meta[10];
	for (int i = 0; i < 10; i++)
	{
		if (i < 5)
			meta[i] = new Cat();
		else
			meta[i] = new Dog();
		meta[i]->makeSound();
	}
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
		delete(meta[i]);
	std::cout << std::endl << "DEEP MEM" << std::endl << std::endl;
	Dog *dog = new Dog();
	for (int i = 0; i < 10; i++)
		dog->RememberIdea("Bone!", i);
	for (int i = 0; i < 10; i++)
	{
		std::cout << i + 1 << ". ";
		dog->ThinkOutLound(i);
	}
	return (0);
}
