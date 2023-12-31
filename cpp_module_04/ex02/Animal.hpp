/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:24:35 by ptungbun          #+#    #+#             */
/*   Updated: 2023/12/02 17:25:50 by marvin           ###   ########.fr       */
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

		std::string	getType(void) const;
		virtual void makeSound(void) const = 0;

		Animal &operator = (const Animal &src);

	protected:

		Animal(void);
		Animal(Animal const &copy);
		virtual ~Animal(void);
		std::string	_type;

};

#endif
