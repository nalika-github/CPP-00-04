/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:57:22 by ptungbun          #+#    #+#             */
/*   Updated: 2024/02/24 20:19:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>
# include "Array.tpp"

template <typename Type> class Array
{
	private:
		Type			*array;
		unsigned int	size;

	public:
		// Constructor and Deconstructor
		Array(void);
		Array(unsigned int n); // Constructor
		Array(const Array &prototype); // Copy Constructor
		~Array(void); // Deconstructor

		// Operator Overload
		Array	&operator = (const Array &rhs);
		Type	&operator [] (unsigned int i);

		// Getter
		unsigned int	size(void) const;
};

#endif
