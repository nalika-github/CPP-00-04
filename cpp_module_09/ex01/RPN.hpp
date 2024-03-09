/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RNP.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:50:23 by ptungbun          #+#    #+#             */
/*   Updated: 2024/03/08 14:31:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <cstdlib>
# include <cstring>

class RPN
{
	private:

		std::stack<int> operands;
		int performOperation(int operand1, int operand2, char operation);

	public:

		RPN() // Default constructor
		{
		}
		
		RPN(const char* expression); // Constructor with expression parameter

		~RPN() // Destructor
		{
		}

		RPN(const RPN& other) // Copy constructor
		{
			this->operands = other.operands;
		}

		RPN& operator=(const RPN& other) // Assignment operator overloading
		{
			if (this != &other) {
				this->operands = other.operands;
			}
			return *this;
		}

		int getResult()
		{
			return operands.top();
		}
};

#endif
