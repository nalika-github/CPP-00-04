/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:24:15 by ptungbun          #+#    #+#             */
/*   Updated: 2023/11/29 11:08:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal()
{
	this->_type = "Dog";
	std::cout << "Dog Constructor called" << std::endl;
}

Dog::Dog(Dog const &copy): Animal()
{
	std::cout << "Dog copy Constructor called" << std::endl;
	*this = copy;
}

Dog::~Dog()
{
	std::cout << "Dog Deconstructor called" << std::endl;
}

std::string	Dog::getType(void) const
{
	return(this->_type);
}

void	Dog::makeSound(void) const
{
	std::cout << "Bark!" << std::endl;
}
