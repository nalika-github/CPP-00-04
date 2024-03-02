/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 22:18:01 by ptungbun          #+#    #+#             */
/*   Updated: 2024/03/02 18:21:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <cstdlib>
# include <algorithm>
# include <stdexcept>
# include <iostream>

# define ERMSG_CAP_EXCEEDED "Capacity exceeded. Cannot add more numbers."
# define ERMSG_CANNOT_FINDSPAN "Cannot find span with less than two numbers."

class Span
{
	private:

		std::vector<int>	numbers;
		unsigned int		maxSize;

	public:

		// Constructor and Deconstructor

		Span(void); // Constructor
		Span(unsigned int maxSize); // Constructor
		Span(const Span &prototype); // Copy Constructor
		~Span(void); // Deconstructor

		// Operator Overload
		Span			&operator = (const Span &rhs);

		// Getter
		unsigned int		getMaxSize() const
		{
			return maxSize;
		}
		std::vector<int>	getNumber() const
		{
			return numbers;
		}

		// Method
		void			addNumber(int number);
		void			addNumber(const std::vector<int> &new_nums);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);
};

#endif

