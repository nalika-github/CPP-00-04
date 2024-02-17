/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:34:28 by ptungbun          #+#    #+#             */
/*   Updated: 2024/02/07 14:02:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
# define AFORM_H

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:

		const std::string	name;
		bool				signedStatus;
		const int			gradeToSign;
		const int			gradeToExecute;

	public:

		// Constructor and Deconstructor
		AForm(const std::string &name, int getGradeToSign, int getGradeToExec); // Constructor
		AForm(const AForm &prototype); // Copy Constructor
		virtual ~AForm(); // Deconstructor

		// Operator Overload
		AForm	&operator = (const AForm &rhs);
		friend std::ostream& operator << (std::ostream &os, const AForm &Aform);

		// Getter
		std::string	getName() const;
		bool		isSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;

		// Member Functions
		virtual void	execute(const Bureaucrat &bureaucrat) const = 0;
		void			beSigned(const Bureaucrat &bureaucrat);

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
