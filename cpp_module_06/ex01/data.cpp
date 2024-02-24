/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:32:53 by ptungbun          #+#    #+#             */
/*   Updated: 2024/02/22 18:27:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.hpp"

Data::Data()
{
}

Data::Data(std::string value) : value(value)
{
}

Data::Data(const Data &prototype) : value(prototype.value)
{
}

Data::~Data()
{
}

Data &Data::operator = (Data const & rhs)
{
	if (this != &rhs)
		value = rhs.value;
	return *this;
}

uintptr_t	serialize(Data *data) {
	return (reinterpret_cast<uintptr_t>(data));
}

Data*	deserialize( uintptr_t data ) {
	return (reinterpret_cast<Data*>(data));
}
