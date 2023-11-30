/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:24:35 by ptungbun          #+#    #+#             */
/*   Updated: 2023/11/30 15:41:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H

# include <ostream>
# include <string>
# include <iostream>

class Brain
{
	public:

		Brain(void);
		Brain(Brain const &copy);
		~Brain();

		void		write_idea(std::string idea, int index);
		std::string	grab_idea(int index);

	private:

		std::string _ideas[100];
};

#endif
