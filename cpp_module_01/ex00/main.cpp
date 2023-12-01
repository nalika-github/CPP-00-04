/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:16:42 by ptungbun          #+#    #+#             */
/*   Updated: 2023/12/01 14:46:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	Zombie*	zombie = new Zombie("common_Zombie");
	zombie->announce();
	delete zombie;

	Zombie* zombie = newZombie("new");
	zombie->announce();
	delete zombie;

	randomChump("random");

	return (0);
}
