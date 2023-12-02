/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:24:15 by ptungbun          #+#    #+#             */
/*   Updated: 2023/12/02 01:11:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << "WrongCat Constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &copy): WrongAnimal()
{
	std::cout << "WrongCat copy Constructor called" << std::endl;
	*this = copy;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Deconstructor called" << std::endl;
}

WrongCat &WrongCat::operator = (const WrongCat &src)
{
	std::cout << "WrongCat Assignation operator called" << std::endl;
	if (this == &src)
		return (*this);

	this->_type = src._type;
	return (*this);
}

std::string	WrongCat::getType(void) const
{
	return(this->_type);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "WrongMeow~~" << std::endl;
}
