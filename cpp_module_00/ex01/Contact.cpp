/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:15:32 by ptungbun          #+#    #+#             */
/*   Updated: 2023/12/01 14:03:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void):
first_name(""),
last_name(""),
nickname(""),
phone_number(""),
darkness_secret("")
{
}

Contact::~Contact(void)
{
}

void		Contact::setFirstName(std::string info)
{
	first_name = info;
}

void		Contact::setLastName(std::string info)
{
	last_name = info;
}

void		Contact::setNickName(std::string info)
{
	nickname = info;
}

void		Contact::setPhoneNumber(std::string info)
{
	phone_number = info;
}

void		Contact::setDarknessSecrete(std::string info)
{
	darkness_secret = info;
}

std::string	Contact::getFirstName(void)
{
	return (first_name);
}

std::string	Contact::getLastName(void)
{
	return (last_name);
}

std::string	Contact::getNickName(void)
{
	return (nickname);
}

std::string	Contact::getPhoneNumber(void)
{
	return (phone_number);
}

std::string	Contact::getDarknessSecrete(void)
{
	return (darkness_secret);
}
