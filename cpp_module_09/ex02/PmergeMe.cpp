/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:14:29 by ptungbun          #+#    #+#             */
/*   Updated: 2024/03/10 21:04:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char* argv[])
{
	if (argc <= 1)
	{
		std::cout << "Error: No input provided\n";
		exit(1);
	}
	for (int i = 1; i < argc; ++i)
	{
		char	*end;
		int		num = strtol(argv[i], &end, 10);
		if (end == argv[i] || *end != '\0' || num <= 0)
		{
			std::cout << "Error: Invalid input => " << argv[i] << std::endl;
			exit(1);
		}
		data.push_back(num);
	}
}

void	PmergeMe::display(const std::string& msg, const std::vector<int>& arr)
{
	std::cout << msg;
	for (size_t i = 0; i < arr.size(); ++i)
		std::cout << arr[i] << " ";
	std::cout << "\n";
}

void	PmergeMe::display(const std::string& msg, const std::deque<int>& arr)
{
	std::cout << msg;
	for (size_t i = 0; i < arr.size(); ++i)
		std::cout << arr[i] << " ";
	std::cout << "\n";
}

void	PmergeMe::mergeInsertSort(std::vector<int>& arr)
{
	for (size_t i = 1; i < arr.size(); ++i)
	{
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void	PmergeMe::mergeInsertSort(std::deque<int>& arr)
{
	for (size_t i = 1; i < arr.size(); ++i)
	{
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void	PmergeMe::sortAndDisplay(void)
{
	std::clock_t start_time1 = std::clock();
	std::vector<int> data_copy1(data);
	mergeInsertSort(data_copy1);
	std::clock_t end_time1 = std::clock();
	std::clock_t start_time2 = std::clock();
	std::deque<int> data_copy2(data.begin(), data.end());
	mergeInsertSort(data_copy2);
	std::clock_t end_time2 = std::clock();
	display("Before: ", data);
	display("After: ", data_copy1);
	std::cout.setf(std::ios::fixed);
	std::cout.precision(3);
	std::cout << "Time to process a range of " << data.size() << " elements with merge-insert sort using vector: "
			<< static_cast<double>(end_time1 - start_time1) * 1000000.0 / CLOCKS_PER_SEC << " us\n";
	std::cout << "Time to process a range of " << data.size() << " elements with merge-insert sort using deque: "
			<< static_cast<double>(end_time2 - start_time2) * 1000000.0 / CLOCKS_PER_SEC << " us\n";
}
