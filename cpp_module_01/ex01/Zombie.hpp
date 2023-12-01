/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:40:58 by ptungbun          #+#    #+#             */
/*   Updated: 2023/12/01 15:19:26 by marvin           ###   ########.fr       */
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

Zombie*	ZombieHorde( int N, std::string name);
Zombie*	newZombie(std::string name);

#endif
