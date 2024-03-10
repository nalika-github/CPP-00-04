/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:14:34 by ptungbun          #+#    #+#             */
/*   Updated: 2024/03/10 21:04:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <algorithm>
# include <ctime>
# include <iomanip>

class PmergeMe
{
	private:
		std::vector<int> data;

	public:

		// Constructor Destructor

		PmergeMe(void)
		{
		}

		PmergeMe(int argc, char* argv[]);

		PmergeMe(const PmergeMe& rhs)
		: data(rhs.data)
		{
		}

		~PmergeMe(void)
		{
		}

		// Public Method

		void display(const std::string& msg, const std::vector<int>& arr);
		void display(const std::string& msg, const std::deque<int>& arr);
		void mergeInsertSort(std::vector<int>& arr);
		void mergeInsertSort(std::deque<int>& arr);
		void sortAndDisplay(void);
};

#endif

