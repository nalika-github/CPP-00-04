/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:24:35 by ptungbun          #+#    #+#             */
/*   Updated: 2023/11/30 14:23:02 by marvin           ###   ########.fr       */
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

		std::string	getType(void)const;
		void 		makeSound(void)const;

		void		RememberIdea(std::string idea, int index);
		void		ThinkOutLound(int index);

	private:

		Brain *_brain;
};

#endif
