/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:24:15 by ptungbun          #+#    #+#             */
/*   Updated: 2023/12/02 17:18:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal()
{
	this->_type = "cat";
	this->_brain = new Brain();
	std::cout << "Cat Constructor called" << std::endl;
}

Cat::Cat(Cat const &copy): Animal()
{
	std::cout << "Cat copy Constructor called" << std::endl;
	*this = copy;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat Deconstructor called" << std::endl;
}

Cat &Cat::operator = (const Cat &src)
{
	std::cout << "Cat Assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	this->_type = src.getType();
	*this->_brain = *src._brain;
	return (*this);
}

std::string	Cat::getType(void) const
{
	return(this->_type);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow~~" << std::endl;
}

void	Cat::ThinkOutLound(int index)
{
	std::cout << this->_brain->grab_idea(index) << std::endl;
}

void	Cat::RememberIdea(std::string idea, int index)
{
	this->_brain->write_idea(idea, index);
}
