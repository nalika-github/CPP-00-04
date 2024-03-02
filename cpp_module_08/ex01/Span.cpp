/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 22:17:49 by ptungbun          #+#    #+#             */
/*   Updated: 2024/03/02 18:23:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Span.hpp"


// Constructor and Deconstructor

Span::Span(void)
{
}

Span::Span(unsigned int maxSize):
maxSize(maxSize)
{
}

Span::Span(const Span &rhs):
numbers(rhs.numbers), maxSize(rhs.maxSize)
{
}

Span::~Span(void)
{
}

// Operator Overload

Span &Span::operator = (Span const & rhs)
{
	if (this != &rhs)
	{
		maxSize = rhs.maxSize;
		numbers = rhs.numbers;
	}
	return *this;
}

// Method

void	Span::addNumber(int number)
{
	if (numbers.size() <= maxSize)
		numbers.push_back(number);
	else
		throw std::out_of_range(ERMSG_CAP_EXCEEDED);
}

void	Span::addNumber(const std::vector<int> &new_nums)
{
	if (numbers.size() + new_nums.size() <= maxSize)
		numbers.insert(numbers.end(), new_nums.begin(), new_nums.end());
	else
		throw std::out_of_range(ERMSG_CAP_EXCEEDED);
}

unsigned int	Span::shortestSpan(void)
{
	int span;

	if (numbers.size() > 1)
	{
		span = abs(numbers[1] - numbers[0]);
		if (numbers.size() > 2)
		{
			for (unsigned int i = 2; i < numbers.size(); i++)
			{
				if (span > abs(numbers[i] - numbers[i - 1]))
					span = abs(numbers[i] - numbers[i - 1]);
			}
		}
		return span;
	}
	else
		throw std::out_of_range(ERMSG_CANNOT_FINDSPAN);
}

unsigned int	Span::longestSpan(void)
{
	int span;

	if (numbers.size() > 1)
	{
		span = abs(numbers[1] - numbers[0]);
		if (numbers.size() > 2)
		{
			for (unsigned int i = 2; i < numbers.size(); i++)
			{
				if (span < abs(numbers[i] - numbers[i - 1]))
					span = abs(numbers[i] - numbers[i - 1]);
			}
		}
		return span;
	}
	else
		throw std::out_of_range(ERMSG_CANNOT_FINDSPAN);
}
