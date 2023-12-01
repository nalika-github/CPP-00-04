/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:15:19 by ptungbun          #+#    #+#             */
/*   Updated: 2023/12/01 14:04:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
# include <sstream>

class Contact
{
	public:
		Contact(void);
		~Contact(void);

		void		setFirstName(std::string info);
		void		setLastName(std::string info);
		void		setNickName(std::string info);
		void		setPhoneNumber(std::string info);
		void		setDarknessSecrete(std::string info);

		std::string	getFirstName(void);
		std::string	getLastName(void);
		std::string	getNickName(void);
		std::string	getPhoneNumber(void);
		std::string	getDarknessSecrete(void);

	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkness_secret;
};

#endif
