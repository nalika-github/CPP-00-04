/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:08:45 by ptungbun          #+#    #+#             */
/*   Updated: 2024/03/07 17:51:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char *argv[])
{
	BTC	btc(argv[1]);

	(void)argv;
	if (argc != 2)
	{
		std::cerr << ERROR_ARGC << std::endl;
		return (EXIT_FAILURE);
	}
	else
		btc.exec();
	return (EXIT_SUCCESS);
}
