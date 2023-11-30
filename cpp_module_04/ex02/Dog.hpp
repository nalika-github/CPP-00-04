/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:24:35 by ptungbun          #+#    #+#             */
/*   Updated: 2023/11/30 14:23:10 by marvin           ###   ########.fr       */
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

		std::string	getType(void)const;
		void makeSound(void)const;

		void		RememberIdea(std::string idea, int index);
		void		ThinkOutLound(int index);

	private:

		Brain *_brain;
};

#endif
