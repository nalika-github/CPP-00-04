/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:02:12 by ptungbun          #+#    #+#             */
/*   Updated: 2023/12/01 13:59:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void):
_n_row(0)
{
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

	i = _n_row - 1;
	while(i >= 0)
	{
		ct = _lst[i];
		std::cout << "|";
		std::cout << "    " << (_n_row - i) << "     ";
		std::cout << "|";
		std::cout.width(10);
		std::cout << std::right << _fit_cell(ct.getFirstName());
		std::cout << "|";
		std::cout.width(10);
		std::cout << std::right << _fit_cell(ct.getLastName());
		std::cout << "|";
		std::cout.width(10);
		std::cout << std::right << _fit_cell(ct.getNickName());
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
	std::cout << "firstname: " << YELB << (_lst[_n_row - index]).getFirstName() << RESET << std::endl;
	std::cout << "lastname: " << YELB << (_lst[_n_row - index]).getLastName() << RESET << std::endl;
	std::cout << "nickname: "  << YELB << (_lst[_n_row - index]).getNickName() << RESET << std::endl;
	std::cout << "telephhone: " << YELB << (_lst[_n_row - index]).getPhoneNumber() << RESET << std::endl;
	std::cout << "darkness_secret: " << YELB << (_lst[_n_row - index]).getDarknessSecrete() << RESET << std::endl;
	std::cout << std::endl;
}

void	PhoneBook::excuse_search(void)
{
	std::string	search;
	int	search_index;

	if (_n_row == 0)
	{
		std::cout << YELB << "\nEmpty PhoneBook not thing to SEARCH\n\n" << RESET;
		return ;
	}
	_table_header_display();
	_table_contact_display();
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
		if (search_index > _n_row)
		{
			std::cout << REDB << search_index << " is out of range" << RESET << std::endl;
			continue ;
		}
		break ;
	}
	display_search_resule(search_index);
}

bool	PhoneBook::isnumber(std::string str)
{
	int	size;
	int	i;

	size = str.size();
	i = 0;
	while (i < size)
	{
		if(!std::isdigit(str.at(i)))
			return (false);
		i++;
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
	if (_n_row == LIMMIT_SIZE)
	{
		_re_arrange();
		(_lst[_n_row - 1]).setFirstName(getline_loop("First Name: ", "please input First Name data", GRNB, REDB));
		(_lst[_n_row - 1]).setLastName(getline_loop("Last Name: ", "please input Last Name data", GRNB, REDB));
		(_lst[_n_row - 1]).setNickName(getline_loop("Nickname: ", "please input Nickname data", GRNB, REDB));
		(_lst[_n_row - 1]).setPhoneNumber(getline_loop("Phone Number: ", "please input Phone Number data", GRNB, REDB));
		(_lst[_n_row - 1]).setDarknessSecrete(getline_loop("Darkness Secrete: ", "please input Darkness Secret data", GRNB, REDB));
		return ;
	}
	(_lst[_n_row]).setFirstName(getline_loop("First Name: ", "please input First Name data", GRNB, REDB));
	(_lst[_n_row]).setLastName(getline_loop("Last Name: ", "please input Last Name data", GRNB, REDB));
	(_lst[_n_row]).setNickName(getline_loop("Nickname: ", "please input Nickname data", GRNB, REDB));
	(_lst[_n_row]).setPhoneNumber(getline_loop("Phone Number: ", "please input Phone Number data", GRNB, REDB));
	(_lst[_n_row]).setDarknessSecrete(getline_loop("Darkness Secrete: ", "please input Darkness Secret data", GRNB, REDB));
	std::cout << std::endl;
	_n_row += 1;
}

void	PhoneBook::_re_arrange(void)
{
	int	i;

	i = 1;
	while (i < LIMMIT_SIZE)
	{
		(_lst)[i - 1] = (_lst)[i];
		i++;
	}
}
