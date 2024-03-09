/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 23:56:28 by ptungbun          #+#    #+#             */
/*   Updated: 2024/03/07 16:52:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>
# include <sstream>
# include <limits>
# include <cctype>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <cfloat>
# include <cmath>

class ScalarConverter
{
	private:
		const std::string	input;
		bool				is_inputzero;
		int					type_Special;
		bool				is_valideInput;
		char				c;
		int					i;
		double				d;
		float				f;

		ScalarConverter(const std::string &input);
		~ScalarConverter(void);

		ScalarConverter	&operator = (const ScalarConverter &rhs);
		bool	isvalideInput();
		int		typeSpecial();
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

