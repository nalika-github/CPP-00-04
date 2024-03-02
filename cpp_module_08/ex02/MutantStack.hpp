/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 22:18:59 by ptungbun          #+#    #+#             */
/*   Updated: 2024/03/02 19:35:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>

template < typename T, class Container = std::deque<T> >
class MutantStack: public std::stack<T, Container>
{
public:

		// Constructor and Destructor
		MutantStack() {} // Default Constructor
		MutantStack(const MutantStack &other) : std::stack<T, Container>(other) {} // Copy Constructor
		~MutantStack() {} // Destructor

		// Getter
		const Container& getContainer() const {
			return std::stack<T, Container>::c;
		}

		// Method
		typedef typename Container::iterator iterator;

		iterator begin()
		{
			return std::stack<T, Container>::c.begin();
		}

		iterator end()
		{
			return std::stack<T, Container>::c.end();
		}
};

#endif
