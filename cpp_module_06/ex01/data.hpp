/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:33:03 by ptungbun          #+#    #+#             */
/*   Updated: 2024/02/22 18:30:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <iostream>
#include <stdint.h>

class Data
{
	private:
		std::string value;

	public:
		Data();
		Data(std::string value);
		Data(const Data &copy);
		~Data();
		Data &operator=(const Data &other);
};

uintptr_t	serialize(Data* ptr);
Data		*deserialize(uintptr_t raw);

#endif
