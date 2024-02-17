/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:03:37 by ptungbun          #+#    #+#             */
/*   Updated: 2024/02/09 17:49:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <cstdlib>
# include "AForm.hpp"

# define MAX_GRADE 150
# define MIN_GRADE 1

class AForm;

class Bureaucrat
{
	private:

		const std::string	name;
		int					grade;

	public:

		// Constructor and Deconstructor
		Bureaucrat(const std::string &name, int grade); // Constructor
		Bureaucrat(const Bureaucrat &prototype); // Copy Constructor
		~Bureaucrat(); // Deconstructor

		// Operator Overload
		Bureaucrat	&operator = (const Bureaucrat &rhs);
		friend std::ostream& operator << (std::ostream &os, const Bureaucrat &bureaucrat);

		// Getter
		std::string	getName() const;
		int			getGrade() const;

		// Method
		void	incrementGrade();
		void	decrementGrade();
		void	signForm(AForm &form);

		// Custom exceptions
		class GradeTooHighException : public std::exception
		{
			public:
			virtual const char* what() const throw()
			{
				return ("Grade is too high");
			}
		};
		class GradeTooLowException : public std::exception
		{
			public:
			virtual const char* what() const throw()
			{
				return ("Grade is too low");
			}
		};
};

#endif
