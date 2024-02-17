/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:03:19 by ptungbun          #+#    #+#             */
/*   Updated: 2024/02/09 20:53:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

# include "Bureaucrat.hpp"
# include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	private:

		std::string	target;

	public:

		// Constructor and Deconstructor
		ShrubberyCreationForm(const std::string &target); // Constructor
		ShrubberyCreationForm(const ShrubberyCreationForm &prototype); // Copy Constructor
		virtual ~ShrubberyCreationForm(); // Deconstructor

		// Operator Overload
		ShrubberyCreationForm	&operator = (const ShrubberyCreationForm &rhs);
		friend std::ostream& operator << (std::ostream &os, const ShrubberyCreationForm &rhs);

		// Getter
		std::string		getTarget() const;

		// Member Functions
		void	execute(const Bureaucrat &bureaucrat) const;
};

std::string const tree =
"          .     .  .      +     .      .          .\n"
"     .       .      .     #       .           .\n"
"        .      .         ###            .      .      .\n"
"      .      .    #:. .:## ##:. .:#   .      .\n"
"          .      .  #### ### ####   .\n"
"       .      #:.    .:# ### #:.    .:#   .        .       .\n"
"  .              ######### #########         .        .\n"
"        .     #:.   #### ### ####   .:#    .       .\n"
"     .     .   #######  ## ##  #######                   .\n"
"                . ## ##### ##### ##            .      .\n"
"    .    #:. ...  .:## ### ### ##:.  ... .:#      .\n"
"      .      ####### ## ##### ## #######       .     .\n"
"    .    .      #####  #######  #####     .      .\n"
"            .            000           .     .\n"
"       .         .   .   000     .        .       .\n"
".. .. ..................O000O........................ ...... ...\n";

#endif

