/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:24:35 by ptungbun          #+#    #+#             */
/*   Updated: 2023/12/02 17:05:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

# include <ostream>
# include <string>
# include <iostream>

class Animal
{
	public:

		Animal(void);
		Animal(Animal const &copy);
		virtual ~Animal(void);
		Animal &operator=(const Animal &src);

		std::string	getType(void) const;
		virtual void makeSound(void) const;

	protected:

		std::string	_type;
};

#endif
