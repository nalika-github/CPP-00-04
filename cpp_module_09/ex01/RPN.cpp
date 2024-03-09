/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:50:13 by ptungbun          #+#    #+#             */
/*   Updated: 2024/03/08 14:38:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	RPN::performOperation(int operand1, int operand2, char operation)
{
	switch(operation)
	{
		case '+':
			return operand1 + operand2;
		case '-':
			return operand1 - operand2;
		case '*':
			return operand1 * operand2;
		case '/':
			if(operand2 != 0)
				return operand1 / operand2;
			else {
				std::cout << "Error: Division by zero" << std::endl;
				exit(EXIT_FAILURE);
			}
		default:
			std::cout << "Error: Invalid operator" << std::endl;
			exit(EXIT_FAILURE);
	}
}

RPN::RPN(const char* expression)
{
	int length = std::strlen(expression);

	for(int i = 0; i < length; ++i)
	{
		if(expression[i] >= '0' && expression[i] <= '9')
			operands.push(expression[i] - '0');
		else if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
		{
			if(operands.size() < 2)
			{
				std::cout << "Error: Not enough operands for operation" << std::endl;
				exit(EXIT_FAILURE);
			}
			int operand2 = operands.top();
			operands.pop();
			int operand1 = operands.top();
			operands.pop();
			int result = performOperation(operand1, operand2, expression[i]);
			operands.push(result);
		}
		else if(expression[i] != ' ')
		{
			std::cout << "Error: Invalid character in expression" << std::endl;
			exit(EXIT_FAILURE);
		}
	}
	if(operands.size() != 1)
	{
		std::cout << "Error: Invalid expression format" << std::endl;
		exit(EXIT_FAILURE);
	}
}
