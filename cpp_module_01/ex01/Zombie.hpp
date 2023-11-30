/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:40:58 by ptungbun          #+#    #+#             */
/*   Updated: 2023/11/19 21:57:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H
# include <iostream>
# include <string>

class Zombie {
	public:
		Zombie(void);
		~Zombie (void);

		void	announce(void);
		void	setName(std::string name);

	private:
		std::string	_name;
};

Zombie*	zombieHorde( int N, std::string name);
Zombie*	newZombie(std::string name);

#endif
