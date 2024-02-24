/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:33:13 by ptungbun          #+#    #+#             */
/*   Updated: 2024/02/22 18:45:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.hpp"

int main(void)
{
	Data *data = new Data();

	std::cout << data << std::endl;
	uintptr_t ptr = serialize(data);
	std::cout << ptr << std::endl;
	Data *dataptr = deserialize(ptr);
	std::cout << dataptr << std::endl;

	delete data;
}
