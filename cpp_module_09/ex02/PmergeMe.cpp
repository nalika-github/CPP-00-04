/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:14:29 by ptungbun          #+#    #+#             */
/*   Updated: 2024/03/10 21:32:42 by marvin           ###   ########.fr       */
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

void	PmergeMe::insertionSort(std::vector<int>& A, int p, int q) {
	for (int i = p; i < q; i++) {
		int tempVal = A[i + 1];
		int j = i + 1;
		while (j > p && A[j - 1] > tempVal) {
			A[j] = A[j - 1];
			j--;
		}
		A[j] = tempVal;
	}
}

void	PmergeMe::merge(std::vector<int>& A, int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	std::vector<int> LA(A.begin() + p, A.begin() + q + 1);
	std::vector<int> RA(A.begin() + q + 1, A.begin() + r + 1);
	int RIDX = 0;
	int LIDX = 0;
	for (int i = p; i <= r; i++) {
		if (RIDX == n2) {
			A[i] = LA[LIDX];
			LIDX++;
		} else if (LIDX == n1) {
			A[i] = RA[RIDX];
			RIDX++;
		} else if (RA[RIDX] > LA[LIDX]) {
			A[i] = LA[LIDX];
			LIDX++;
		} else {
			A[i] = RA[RIDX];
			RIDX++;
		}
	}
}

void	PmergeMe::sort(std::vector<int>& A, int p, int r) {
	if (r - p > K) {
		int q = (p + r) / 2;
		sort(A, p, q);
		sort(A, q + 1, r);
		merge(A, p, q, r);
	} else {
		insertionSort(A, p, r);
	}
}

void	PmergeMe::insertionSort(std::deque<int>& A, int p, int q) {
	for (int i = p; i < q; i++) {
		int tempVal = A[i + 1];
		int j = i + 1;
		while (j > p && A[j - 1] > tempVal) {
			A[j] = A[j - 1];
			j--;
		}
		A[j] = tempVal;
	}
}

void	PmergeMe::merge(std::deque<int>& A, int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	std::deque<int> LA(A.begin() + p, A.begin() + q + 1);
	std::deque<int> RA(A.begin() + q + 1, A.begin() + r + 1);
	int RIDX = 0;
	int LIDX = 0;
	for (int i = p; i <= r; i++) {
		if (RIDX == n2) {
			A[i] = LA[LIDX];
			LIDX++;
		} else if (LIDX == n1) {
			A[i] = RA[RIDX];
			RIDX++;
		} else if (RA[RIDX] > LA[LIDX]) {
			A[i] = LA[LIDX];
			LIDX++;
		} else {
			A[i] = RA[RIDX];
			RIDX++;
		}
	}
}

void	PmergeMe::sort(std::deque<int>& A, int p, int r) {
	if (r - p > K) {
		int q = (p + r) / 2;
		sort(A, p, q);
		sort(A, q + 1, r);
		merge(A, p, q, r);
	} else {
		insertionSort(A, p, r);
	}
}

void	PmergeMe::sortAndDisplay(void)
{
	std::clock_t start_time1 = std::clock();
	std::vector<int> data_copy1(data);
	sort(data_copy1, 0, data_copy1.size() - 1);
	std::clock_t end_time1 = std::clock();
	std::clock_t start_time2 = std::clock();
	std::deque<int> data_copy2(data.begin(), data.end());
	sort(data_copy2, 0, data_copy2.size() - 1);
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
