/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:04:08 by ptungbun          #+#    #+#             */
/*   Updated: 2024/02/09 20:53:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

# include "Bureaucrat.hpp"
# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private:

		std::string	target;

	public:

		// Constructor and Deconstructor
		PresidentialPardonForm(const std::string &target); // Constructor
		PresidentialPardonForm(const PresidentialPardonForm &prototype); // Copy Constructor
		~PresidentialPardonForm(); // Deconstructor

		// Operator Overload
		PresidentialPardonForm	&operator = (const PresidentialPardonForm &rhs);
		friend std::ostream& operator << (std::ostream &os, const PresidentialPardonForm &rhs);

		// Getter
		std::string	getTarget() const;

		// Member Functions
		void	execute(const Bureaucrat &bureaucrat) const;
};

#endif

