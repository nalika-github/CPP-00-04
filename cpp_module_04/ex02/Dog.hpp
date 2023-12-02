/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:24:35 by ptungbun          #+#    #+#             */
/*   Updated: 2023/12/02 17:27:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Dog_H
# define Dog_H

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
	public:

		Dog(void);
		Dog(Dog const &copy);
		~Dog(void);
		Dog &operator=(const Dog &src);

		std::string	getType(void)const;
		void makeSound(void)const;

		void		RememberIdea(std::string idea, int index);
		void		ThinkOutLound(int index);

	private:

		Brain *_brain;
};

#endif
