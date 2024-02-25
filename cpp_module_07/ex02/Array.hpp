/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:57:22 by ptungbun          #+#    #+#             */
/*   Updated: 2024/02/25 21:23:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename Type> class Array
{
	private:
		Type			*array;
		unsigned int	size;

	public:
		// Constructor and Deconstructor
		Array(void): array(NULL), size(0) {}
		Array(unsigned int n): array(new Type[n]), size(n) {} // Constructor
		Array(const Array &prototype) // Copy Constructor
		{
			array = new Type[prototype.size];
			size = prototype.size;
			for (unsigned int i = 0; i < size; i++)
				array[i] = prototype.array[i];
		}
		~Array(void) {delete [] array;} // Deconstructor

		// Operator Overload
		Array	&operator = (const Array &rhs)
		{
			if (this != &rhs)
			{
				delete [] array;
				size = rhs.size;
				array = new Type[size];
				for (unsigned int i = 0; i < size; i++)
					array[i] = rhs.array[i];
			}
			return (*this);
		}
		Type	&operator [] (unsigned int i)
		{
			if (i >= size)
				throw std::exception();
			return (array[i]);
		}

		// Getter
		unsigned int	getSize(void) const {return (size);}
};

#endif
