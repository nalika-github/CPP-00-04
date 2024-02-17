/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:34:28 by ptungbun          #+#    #+#             */
/*   Updated: 2024/02/06 21:50:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:

		const std::string	name;
		bool				signedStatus;
		const int			gradeToSign;
		const int			gradeToExecute;

	public:

		// Constructor and Deconstructor
		Form(const std::string &name, int getGradeToSign, int getGradeToExec); // Constructor
		Form(const Form &prototype); // Copy Constructor
		~Form(); // Deconstructor

		// Operator Overload
		Form	&operator = (const Form &rhs);
		friend std::ostream& operator << (std::ostream &os, const Form &form);

		// Getter
		std::string	getName() const;
		bool		isSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;

		// Member Functions
		void		beSigned(const Bureaucrat &bureaucrat);

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
