/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:14:34 by ptungbun          #+#    #+#             */
/*   Updated: 2024/03/10 21:30:30 by marvin           ###   ########.fr       */
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

const int K = 5;

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
		void insertionSort(std::vector<int>& A, int p, int q);
		void insertionSort(std::deque<int>& A, int p, int q);
		void merge(std::deque<int>& A, int p, int q, int r);
		void merge(std::vector<int>& A, int p, int q, int r);
		void sort(std::vector<int>& A, int p, int r);
		void sort(std::deque<int>& A, int p, int r);
		void sortAndDisplay(void);
};

#endif

