/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:16:42 by ptungbun          #+#    #+#             */
/*   Updated: 2023/12/01 21:58:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	Zombie*	zombie = new Zombie("common_Zombie");
	zombie->announce();
	delete zombie;

	Zombie* z = newZombie("new");
	z->announce();
	delete z;

	randomChump("random");

	return (0);
}
