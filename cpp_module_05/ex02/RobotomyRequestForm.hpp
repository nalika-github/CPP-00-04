/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:03:46 by ptungbun          #+#    #+#             */
/*   Updated: 2024/02/09 20:53:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

# include "Bureaucrat.hpp"
# include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	private:

		std::string	target;

	public:

		// Constructor and Deconstructor
		RobotomyRequestForm(const std::string &target); // Constructor
		RobotomyRequestForm(const RobotomyRequestForm &prototype); // Copy Constructor
		~RobotomyRequestForm(); // Deconstructor

		// Operator Overload
		RobotomyRequestForm	&operator = (const RobotomyRequestForm &rhs);
		friend std::ostream& operator << (std::ostream &os, const RobotomyRequestForm &rhs);

		// Getter
		std::string	getTarget() const;

		// Member Functions
		void	execute(const Bureaucrat &bureaucrat) const;
};

#endif
