/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:24:35 by ptungbun          #+#    #+#             */
/*   Updated: 2023/12/02 17:26:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
	public:

		Cat(void);
		Cat(Cat const &copy);
		~Cat(void);
		Cat &operator=(const Cat &src);

		std::string	getType(void)const;
		void 		makeSound(void)const;

		void		RememberIdea(std::string idea, int index);
		void		ThinkOutLound(int index);

	private:

		Brain *_brain;
};

#endif
