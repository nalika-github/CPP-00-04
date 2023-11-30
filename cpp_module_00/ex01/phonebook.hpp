/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:37:03 by ptungbun          #+#    #+#             */
/*   Updated: 2023/11/06 10:33:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# include <iostream>
# include <sstream>

/* text color */
# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define YEL "\e[0;33m"
# define BLU "\e[0;34m"
# define PUR "\e[0;35m"
# define CYN "\e[0;36m"
# define WHT "\e[0;37m"

/* bold text color */
# define REDB "\e[1;31m"
# define GRNB "\e[1;32m"
# define YELB "\e[0;33m"
# define BLUB "\e[1;34m"
# define PURB "\e[1;35m"
# define CYNB "\e[1;36m"
# define WHTB "\e[1;37m"

# define RESET "\033[0m"
# define LIMMIT_SIZE	8

class Contact
{
	public:
		Contact(void);
		~Contact(void);

		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkness_secret;
};

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void		getline_cmd_display(void);
		void		excuse_search(void);
		void		excuse_add(void);
		void		init_set(void);
		std::string	getline_loop(std::string prompt_msg ,std::string err_msg, std::string prompt_color, std::string err_color);
		bool		isnumber(std::string &s);
		void		display_search_resule(int search_index);

	private:
		int			_n_row;
		Contact		_lst[LIMMIT_SIZE];
		void		_table_header_display(void);
		void		_re_arrange(void);
		void		_table_contact_display(void);
		std::string		_fit_cell(std::string word);
};
#endif
