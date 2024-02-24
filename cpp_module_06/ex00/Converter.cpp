/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 23:56:21 by ptungbun          #+#    #+#             */
/*   Updated: 2024/02/22 16:41:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

ScalarConverter::ScalarConverter(const std::string &input):
input(input)
{
	type_Special = typeSpecial();
	is_valideInput = isvalideInput();
	is_inputzero = isInputZero();
	d = std::strtod(input.c_str(), NULL);
	i = static_cast<int>(d);
	getCharInput();
	f = std::strtof(input.c_str(), NULL);
}

ScalarConverter::~ScalarConverter()
{
}

bool	ScalarConverter::isvalideInput()
{
	int	dot;
	int	f;

	dot = 0;
	f = 0;
	for(std::string::const_iterator it = input.begin(); it != input.end(); it++)
	{
		if (*it == '.')
			dot++;
		else if (*it == 'f')
			f++;
	}
	if ((f > 1 || dot > 1) && type_Special == 0)
		return false;
	if (f > 0 && *(input.end() - 1) != 'f')
		return false;
	return true;
}

bool	ScalarConverter::isInputZero()
{
	int	dot;
	int	f;

	if (input.size() == 1 && input[0] != '0')
		return false;
	dot = 0;
	f = 0;
	for(std::string::const_iterator it = input.begin(); it != input.end(); it++)
	{
		if (*it == '.')
			dot++;
		else if (*it == 'f')
			f++;
		if (*it != 'f' && *it != '.'&& *it != '0')
		{
			std::cout << "false\n";
			return false;
		}
	}
	std::cout << "true\n";
	return true;
}

int	ScalarConverter::typeSpecial()
{
	if (input == "+inf" || input == "-inf" || input == "nan")
		return 1;
	else if (input == "+inff" || input == "-inff" || input == "nanf")
		return 2;
	return 0;
}

void	ScalarConverter::getCharInput()
{
	if (input.size() == 1 && (std::isalpha(input[0])))
		c = input[0];
	else
		c = static_cast<char>(d);;
}

ScalarConverter &ScalarConverter::operator = (const ScalarConverter &rhs)
{
	is_inputzero = rhs.is_inputzero;
	c = rhs.c;
	i = rhs.i;
	d = rhs.d;
	f = rhs.f;
	return (*this);
}

void	ScalarConverter::printChar(void)
{
	if (input.size() == 1 && (std::isalpha(input[0])))
		std::cout << "char: '" << c << "'" << std::endl;
	else if (i == 0 && !is_inputzero)
		std::cout << "char: imposible" << std::endl;
	else if (is_inputzero || i < 32 || i > 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
}

void	ScalarConverter::printInt(void)
{
	if ((!is_inputzero && d == 0) || type_Special > 0)
		std::cout << "int: imposible" << std::endl;
	else if (d > INT_MAX || d < INT_MIN)
		std::cout << "int: overflow" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
}

void	ScalarConverter::printDouble(void)
{
	if (!is_inputzero && d == 0)
		std::cout << "double: imposible" << std::endl;
	else if (type_Special == 1)
		std::cout << "double: " << input << std::endl;
	else if (type_Special == 2)
	{
		if (input == "+inff")
			std::cout << "double: " << "+inf" << std::endl;
		else if (input == "-inff")
			std::cout << "double: " << "-inf" << std::endl;
		else if (input == "nanf")
			std::cout << "double: " << "nan" << std::endl;
	}
	else if ((floor(d) - d) == 0)
		std::cout << "double: " << d << ".0" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}

void	ScalarConverter::printFloat(void)
{
	if ((!is_inputzero && d == 0) && type_Special == 0)
		std::cout << "float: imposible" << std::endl;
	else if (type_Special == 1)
		std::cout << "float: " << input << "f" << std::endl;
	else if (type_Special == 2)
		std::cout << "float: " << input << std::endl;
	else if ((floor(f) - f) == 0)
		std::cout << "float: " << d << ".0f" << std::endl;
	else
		std::cout << "float: " << d << "f" << std::endl;
}

void	ScalarConverter::convert(const std::string &input)
{
	ScalarConverter	SC = ScalarConverter(input);

	if (!SC.isvalideInput())
		std::cout << "Invalid input" << std::endl;
	else
	{
		SC.printChar();
		SC.printInt();
		SC.printDouble();
		SC.printFloat();
	}
}

// void	ScalarConverter::convert(const std::string &input)
// {
	// char	c;
	// int		i;
	// double	d;
	// float	f;

	// std::istringstream(input) >> i;
	// std::istringstream(input) >> d;
	// std::istringstream(input) >> f;
	// is_inputzero(input);
	// if (input.size() == 1 && (std::isalpha(input[0])))
	// {
	// 	i = input[0];
	// 	c = i;
	// 	if (std::isprint(c))
	// 		std::cout << "char: '" << c << "'" << std::endl;
	// 	else
	// 		std::cout << "char: Non displayable" << std::endl;
	// }
	// else if (d && i == d)
	// {
	// 	c = i;
	// 	if (std::isprint(c))
	// 		std::cout << "char: '" << c << "'" << std::endl;
	// 	else
	// 		std::cout << "char: Non displayable" << std::endl;
	// }
	// else
	// 	std::cout << "char: imposible"  << std::endl;
	// if (i )
	// std::cout << "i = " << i << std::endl;
	// std::cout << "d = " << d << std::endl;
	// std::cout << "f = " << f << std::endl;
// }

// // ตัวอย่างการแปลงประเภทข้อมูล
// float f = 3.14;
// int i = static_cast<int>(f); // แปลงค่าทศนิยมเป็นเลขจำนวนเต็ม

// // ตัวอย่างการแปลง pointer
// Base* basePtr = new Derived();
// Derived* derivedPtr = static_cast<Derived*>(basePtr); // แปลง pointer จาก Base เป็น Derived (downcasting)
