/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:43:18 by ptungbun          #+#    #+#             */
/*   Updated: 2024/03/08 14:01:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <iostream>
# include <string>
# include <sstream>
# include <limits.h>
# include <stdlib.h>
# include <fstream>

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

# define ERROR_UNABLE_OPEN "\e[1;31mError: \e[0;33mUnable to open file \033[0m "
# define ERROR_INVALID_VAL "\e[1;31mError: \e[0;33minvalid value.\033[0m "
# define ERROR_ARGC "\e[1;31mError: \e[0;33mEnsure your input conforms to the required format: \e[1;32m./btc <input file>\033[0m"
# define ERROR_BAD_INPUT "\e[1;31mError: \e[0;33mbad input =>\033[0m "
# define ERROR_TOOLARGE_VAL "\e[1;31mError: \e[0;33mtoo large a number.\033[0m "
# define ERROR_NEG_VAL "\e[1;31mError: \e[0;33mnot a positive number.\033[0m "

class BTC
{
	private:
		//Attribute

		std::string							inputFileName;
		std::string							dataFileName;
		std::map<std::string, double>		dataTable;

		// Private Method

		void	trimSpace(std::string &str);

		bool	isSpace(char c);
		bool	isValidFormat(std::string line, char deli);
		bool	isLeapYear(int y);
		bool	isValidDate(std::string& key);
		bool	isValidValue(std::string& key);
		bool	setDataTable(void);
		bool	printReslut(void);

		int		dataToTimeStamp(std::string key);

		double	getClosetValue(std::string key);

		std::map<std::string, double>	setResultTable(void);

	public:
		// Constructor and Deconstructor

		BTC(void) // Default Constructor
		: inputFileName(""), dataFileName("data.csv")
		{
		}

		BTC(std::string inputFileName) // input_file name Constructor
		: inputFileName(inputFileName), dataFileName("data.csv")
		{
		}

		BTC(std::string inputFileName, std::string dataFileName) // input_file name and data_file name Constructor
		: inputFileName(inputFileName), dataFileName(dataFileName)
		{
		}

		BTC(BTC const &rhs) // Copy Constructor
		{
			*this = rhs;
		}

		~BTC(void)
		{
		}

		// Operator overloading
		BTC &operator = (BTC const & rhs);

		// Getter
		std::string	getDataFileName(void) const
		{
			return (dataFileName);
		}
		std::string	getInputFileName(void) const
		{
			return (inputFileName);
		}

		// Public Method
		void	exec(void);
};

// std::ostream & operator << (std::ostream &o, BTC const & i);

#endif
