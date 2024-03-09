/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:49:58 by ptungbun          #+#    #+#             */
/*   Updated: 2024/03/08 14:33:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char *argv[])
{
	if(argc != 2) {
		std::cout << "Usage: " << argv[0] << " <RPN_expression>" << std::endl;
		return EXIT_FAILURE;
	}
	RPN rpn(argv[1]);
	int result = rpn.getResult();
	std::cout << "Result: " << result << std::endl;
	return EXIT_SUCCESS;
}
