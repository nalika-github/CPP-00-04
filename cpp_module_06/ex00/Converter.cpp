/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 23:56:21 by ptungbun          #+#    #+#             */
/*   Updated: 2024/02/17 18:54:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

ScalarConverter::ScalarConverter(const std::string &input):
input(input)
{
	is_Invalide = is
	is_inputzero = isInputZero();
	is_number = isInputNumber();
	std::istringstream(input) >> i;
	getCharInput();
	std::istringstream(input) >> d;
	std::istringstream(input) >> f;
}

ScalarConverter::~ScalarConverter()
{
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
			return false;
	}
	return true;
}

void	ScalarConverter::getCharInput()
{
	if (input.size() == 1 && (std::isalpha(input[0])))
		c = input[0];
	else
		c = i;
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

void	ScalarConverter::convert(const std::string &input)
{
	ScalarConverter	SC = ScalarConverter(input);

	// std::cout << "char: '" << SC.c << "'" << std::endl;
	// std::cout << "i = " << SC.i << std::endl;
	// std::cout << "d = " << SC.d << std::endl;
	// std::cout << "f = " << SC.f << std::endl;
	SC.printChar();
	// SC.printInt();
	// SC.printDouble();
	// SC.printFloat();
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
