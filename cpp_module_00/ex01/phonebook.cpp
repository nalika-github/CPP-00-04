/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:02:12 by ptungbun          #+#    #+#             */
/*   Updated: 2023/11/06 10:38:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Contact::Contact(void)
{
	this->first_name = "";
	this->last_name = "";
	this->nickname = "";
	this->phone_number = "";
	this->darkness_secret = "";
}

Contact::~Contact(void)
{
	;
}

PhoneBook::PhoneBook(void)
{
	this->_n_row = 0;
}

PhoneBook::~PhoneBook(void) {
}

void	PhoneBook::getline_cmd_display(void)
{
	std::cout << "PhoneBook type your command (";
	std::cout << GRNB << "ADD" << RESET << ", ";
	std::cout << YELB << "SEARCH" << RESET << ", ";
	std::cout << REDB << "EXIT" << RESET;
	std::cout << ") : " << RESET;
}

void	PhoneBook::_table_header_display(void)
{
	std::cout << "" << std::endl;
	std::cout << "+";
	std::cout.width(44);
	std::cout.fill('-');
	std::cout << "+";
	std::cout << std::endl;
	std::cout.fill(' ');
	std::cout << "|  index   |";
	std::cout << "first name|" << " last name|" << " nickname |" << std::endl;
	std::cout << "+";
	std::cout.width(44);
	std::cout.fill('-');
	std::cout << "+";
	std::cout << "" << std::endl;
	std::cout.fill(' ');
}

void	PhoneBook::_table_contact_display(void)
{
	int		i;
	Contact	ct;

	i = this->_n_row - 1;
	while(i >= 0)
	{
		ct = this->_lst[i];
		std::cout << "|";
		std::cout << "    " << (this->_n_row - i) << "     ";
		std::cout << "|";
		std::cout.width(10);
		std::cout << std::right << this->_fit_cell(ct.first_name);
		std::cout << "|";
		std::cout.width(10);
		std::cout << std::right << this->_fit_cell(ct.last_name);
		std::cout << "|";
		std::cout.width(10);
		std::cout << std::right << this->_fit_cell(ct.nickname);
		std::cout << "|";
		std::cout << std::endl;
		std::cout << "+";
		std::cout.width(44);
		std::cout.fill('-');
		std::cout << "+";
		std::cout << "" << std::endl;
		std::cout.fill(' ');
		i--;
	}
}

std::string	PhoneBook::_fit_cell(std::string word)
{
	std::string	fit_word;

	if (word.size() <= 10)
		return (word);
	else
	{
		fit_word = word.substr(0, 9);
		fit_word = fit_word + ".";
	}
	return (fit_word);
}

void	PhoneBook::display_search_resule(int index)
{
	std::cout << std::endl;
	std::cout << "firstname: " << YELB << (this->_lst[this->_n_row - index]).first_name << RESET << std::endl;
	std::cout << "lastname: " << YELB << (this->_lst[this->_n_row - index]).last_name << RESET << std::endl;
	std::cout << "nickname: "  << YELB << (this->_lst[this->_n_row - index]).nickname << RESET << std::endl;
	std::cout << "telephhone: " << YELB << (this->_lst[this->_n_row - index]).phone_number << RESET << std::endl;
	std::cout << "darkness_secret: " << YELB << (this->_lst[this->_n_row - index]).darkness_secret << RESET << std::endl;
	std::cout << std::endl;
}

void	PhoneBook::excuse_search(void)
{
	std::string	search;
	int	search_index;

	if (this->_n_row == 0)
	{
		std::cout << YELB << "\nEmpty PhoneBook not thing to SEARCH\n\n" << RESET;
		return ;
	}
	this->_table_header_display();
	this->_table_contact_display();
	std::cout << std::endl;
	while(true)
	{
		search = getline_loop("to SEARCH index : ", "please input index to SEARCH", YELB, REDB);
		if (isnumber(search) == false)
		{
			std::cout << REDB << search << " isn't number" << RESET << std::endl;
			continue ;
		}
		std::istringstream(search) >> search_index;
		if (search_index > this->_n_row)
		{
			std::cout << REDB << search_index << " is out of range" << RESET << std::endl;
			continue ;
		}
		break ;
	}
	display_search_resule(search_index);
}

bool	PhoneBook::isnumber(std::string &s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end())
	{
		if(!std::isdigit(*it))
			return (false);
		++it;
	}
	return (true);
}

std::string	PhoneBook::getline_loop(std::string prompt_msg ,std::string err_msg, std::string prompt_color, std::string err_color)
{
	std::string Contact;

	while(true)
	{
		std::cout << prompt_color << prompt_msg << RESET;
		std::getline(std::cin, Contact);
		if (Contact.empty())
		{
			std::cout << err_color << err_msg << RESET << std::endl;
			continue ;
		}
		break ;
	}
	return (Contact);
}

void	PhoneBook::excuse_add(void)
{
	std::cout << std::endl;
	std::cout << GRNB << "----ADD NEW CONTACT----\n\n" << RESET;
	if (this->_n_row == LIMMIT_SIZE)
	{
		this->_re_arrange();
		(this->_lst[this->_n_row - 1]).first_name = getline_loop("First Name: ", "please input First Name data", GRNB, REDB);
		(this->_lst[this->_n_row - 1]).last_name = getline_loop("Last Name: ", "please input Last Name data", GRNB, REDB);
		(this->_lst[this->_n_row - 1]).nickname = getline_loop("Nickname: ", "please input Nickname data", GRNB, REDB);
		(this->_lst[this->_n_row - 1]).phone_number = getline_loop("Phone Number: ", "please input Phone Number data", GRNB, REDB);
		(this->_lst[this->_n_row - 1]).darkness_secret = getline_loop("Darkness Secrete: ", "please input Darkness Secret data", GRNB, REDB);
		return ;
	}
	(this->_lst[this->_n_row]).first_name = getline_loop("first name: ", "please input first name data", GRNB, REDB);
	(this->_lst[this->_n_row]).last_name = getline_loop("last name: ", "please input last name data", GRNB, REDB);
	(this->_lst[this->_n_row]).nickname = getline_loop("nickname: ", "please input nickname data", GRNB, REDB);
	(this->_lst[this->_n_row]).phone_number = getline_loop("phone number: ", "please input phone number data", GRNB, REDB);
	(this->_lst[this->_n_row]).darkness_secret = getline_loop("darkness secrete: ", "please input darkness secret data", GRNB, REDB);
	std::cout << std::endl;
	this->_n_row += 1;
}

void	PhoneBook::_re_arrange(void)
{
	int	i;

	i = 1;
	while (i < LIMMIT_SIZE)
	{
		(this->_lst)[i - 1] = (this->_lst)[i];
		i++;
	}
}
