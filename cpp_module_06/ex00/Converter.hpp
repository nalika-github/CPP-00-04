/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 23:56:28 by ptungbun          #+#    #+#             */
/*   Updated: 2024/02/17 17:05:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>
# include <sstream>
# include <limits>
# include <climits>

class ScalarConverter
{
	private:
		const std::string	input;
		bool				is_inputzero;
		char				c;
		int					i;
		double				d;
		float				f;

		ScalarConverter(const std::string &input);
		~ScalarConverter(void);

		ScalarConverter	&operator = (const ScalarConverter &rhs);
		void	getCharInput();
		bool	isInputZero();
		void	printChar();
		void	printInt();
		void	printDouble();
		void	printFloat();

	public:
		static void	convert(const std::string &input);
};

#endif

