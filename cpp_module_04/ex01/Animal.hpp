/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:24:35 by ptungbun          #+#    #+#             */
/*   Updated: 2023/11/29 19:01:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

# include <ostream>
# include <string>
# include <iostream>
# include "Brain.hpp"

class Animal
{
	public:

		Animal(void);
		Animal(Animal const &copy);
		virtual ~Animal(void);

		std::string	getType(void) const;
		virtual void makeSound(void) const;

		Animal &operator = (const Animal &src);

	protected:

		std::string	_type;
};

#endif
