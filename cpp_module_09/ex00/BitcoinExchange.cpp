/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:43:28 by ptungbun          #+#    #+#             */
/*   Updated: 2024/03/08 02:21:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Operator overloading

BTC		&BTC::operator = (BTC const & rhs)
{
	if (this == &rhs)
		return *this;
	this->dataFileName = rhs.dataFileName;
	this->inputFileName = rhs.inputFileName;
	return *this;
}

// Private Method

bool	BTC::isSpace(char c)
{
	return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

void	BTC::trimSpace(std::string& str) {
	std::string::size_type start = str.find_first_not_of(" \t\n\r");
	if (start == std::string::npos) {
		str = "";
		return;
	}
	std::string::size_type end = str.find_last_not_of(" \t\n\r");
	str = str.substr(start, end - start + 1);
}

bool	BTC::setDataTable(void)
{
	std::ifstream	file(dataFileName.c_str());
	std::string		line;
	std::string		key;
	std::string		value;
	double			d_value;

	if (!file.is_open())
	{
		std::cerr << ERROR_UNABLE_OPEN << dataFileName << std::endl;
		return false;
	}
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		if(!isValidFormat(line, ','))
		{
			std::cout << line << std::endl;
			file.close();
			return false;
		}
		trimSpace(line);
		if (std::getline(ss, key, ',') && std::getline(ss, value))
		{
			d_value = std::strtod(value.c_str(), NULL);
			dataTable[key] = d_value;
		}
	}
	file.close();
	return true;
}

bool	BTC::printReslut(void)
{
	std::ifstream	file(inputFileName.c_str());
	std::string		line;
	std::string		key;
	std::string		value;
	double			dataVal;
	double			inputVal;

	if (!file.is_open())
	{
		std::cerr << ERROR_UNABLE_OPEN << inputFileName << std::endl;
		file.close();
		return false;
	}
	std::getline(file, line);
	while (std::getline(file, line))
	{
		trimSpace(line);
		std::stringstream ss(line);
		if(!isValidFormat(line, '|'))
			continue ;
		else if (std::getline(ss, key, '|') && std::getline(ss, value))
		{
			trimSpace(key);
			trimSpace(value);
			if (!isValidDate(key))
				continue ;
			else if (!isValidValue(value))
				continue ;
			else
			{
				dataVal = getClosetValue(key);
				inputVal = std::strtod(value.c_str(), NULL);
				std::cout << "\e[1;32m" << key << " => " << value << " = "
				<< dataVal * inputVal << "\e[0m" << std::endl;
			}
		}
	}
	file.close();
	return true;
}

bool	BTC::isValidFormat(std::string line, char deli)
{
	std::string	date;
	std::string	value;
	std::string	key;
	int			pos;
	int			i;

	pos = 0;
	i = 0;
	for(std::string::iterator it=line.begin(); it!=line.end(); ++it)
	{
		if (*it == deli)
			i++;
		pos++;
	}
	if (deli == '|' && i != 1 && pos != 10)
	{
		std::cerr << ERROR_BAD_INPUT << line << std::endl;
		return false;
	}
	else if (deli == ',' && i != 1 && pos != 10)
	{
		std::cerr << ERROR_BAD_INPUT << line << std::endl;
		return false;
	}
	std::stringstream ss(line);
	if (deli == '|' && !(std::getline(ss, key, '|') && std::getline(ss, value)))
	{
		std::cerr << ERROR_BAD_INPUT << line << std::endl;
		return false;
	}
	return true;
}

bool	BTC::isLeapYear(int y)
{
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
		return true;
	else
		return false;
}

bool	BTC::isValidDate(std::string& key)
{
	int	y;
	int	m;
	int	d;

	if (key.length() != 10 || key.at(4) != '-' || key.at(7) != '-')
	{
		std::cerr << ERROR_BAD_INPUT << key << std::endl;
		return false;
	}
	y = atoi(key.substr(0, 4).c_str());
	m = atoi(key.substr(5, 2).c_str());
	d = atoi(key.substr(8, 2).c_str());
	if (y < 1990 || m < 1 || m > 12 || d < 1 || d > 31)
	{
		std::cerr << ERROR_BAD_INPUT << key << std::endl;
		return false;
	}
	else if (m == 2)
	{
		if (isLeapYear(y) && d > 29)
		{
		std::cerr << ERROR_BAD_INPUT << key << std::endl;
		return false;
		}
		else if (!isLeapYear(y) && d > 28)
		{
			std::cerr << ERROR_BAD_INPUT << key << std::endl;
			return false;
		}
	}
	else if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
	{
		std::cerr << ERROR_BAD_INPUT << key << std::endl;
		return false;
	}
	return true;
}

bool	BTC::isValidValue(std::string& s_value)
{
	char	*end;
	double	value;

	if (s_value.empty())
	{
		std::cout << ERROR_BAD_INPUT << s_value << std::endl;
		return false;
	}
	value = std::strtod(s_value.c_str(), &end);
	if (end == s_value.c_str() || *end != '\0' || value > 1000 || value < 0)
	{
		std::cerr << (value > 1000 ? ERROR_TOOLARGE_VAL : \
		(value < 0 ? ERROR_NEG_VAL : ERROR_INVALID_VAL)) << std::endl;
		return false;
	}
	return true;
}

double	BTC::getClosetValue(std::string key)
{
	int			targetTimestamp;
	int			minDifference;
	double		closestVal;

	targetTimestamp = dataToTimeStamp(key);
	minDifference = INT_MAX;
	for (std::map<std::string, double>::iterator it = dataTable.begin(); it != dataTable.end(); ++it)
	{
		int timestamp = dataToTimeStamp(it->first);
		int difference = std::abs(timestamp - targetTimestamp);
		if (difference < minDifference)
		{
			minDifference = difference;
			closestVal = it->second;
		}
	}
	return closestVal;
}

int		BTC::dataToTimeStamp(std::string key)
{
	int dt = 60 * 24;
	int	y = atoi(key.substr(0, 4).c_str());
	int	m = atoi(key.substr(5, 2).c_str());
	int	d = atoi(key.substr(8, 2).c_str());
	return (y * 365 * dt) + (m * 30 * dt) + (d * dt);
}

void	BTC::exec(void)
{
	if(!setDataTable())
		return ;
	printReslut();
}
