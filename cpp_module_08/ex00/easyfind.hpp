/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 22:16:34 by ptungbun          #+#    #+#             */
/*   Updated: 2024/03/02 17:33:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <vector>
# include <algorithm>
# include <stdexcept>

class easyFindException : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return "NOT FOUND.";
	}
};

template <typename T>
typename T::iterator easyfind(T &container, const int &value)
{
	typename T::iterator it = container.begin();
	while (it != container.end())
	{
		if (*it == value)
			return it;
		++it;
	}
	throw easyFindException();
}

#endif
