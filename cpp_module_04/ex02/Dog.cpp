/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:24:15 by ptungbun          #+#    #+#             */
/*   Updated: 2023/11/30 14:22:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal()
{
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << "Dog Constructor called" << std::endl;
}

Dog::Dog(Dog const &copy): Animal()
{
	std::cout << "Dog copy Constructor called" << std::endl;
	*this = copy;
}

Dog::~Dog()
{
	delete this->_brain;
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

void	Dog::ThinkOutLound(int index)
{
	std::cout << this->_brain->grab_idea(index) << std::endl;
}

void	Dog::RememberIdea(std::string idea, int index)
{
	this->_brain->write_idea(idea, index);
}
