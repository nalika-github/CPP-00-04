/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:24:15 by ptungbun          #+#    #+#             */
/*   Updated: 2023/11/29 12:26:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void): _type("undefine")
{
	std::cout << "Animal Constructor called" << std::endl;
}

Animal::Animal(Animal const &copy)
{
	std::cout << "Animal copy Constructor called" << std::endl;
	*this = copy;
}

Animal::~Animal()
{
	std::cout << "Animal Deconstructor called" << std::endl;
}

std::string	Animal::getType(void) const
{
	return(this->_type);
}

void	Animal::makeSound(void) const
{
	std::cout << "...." << std::endl;
}
