/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 23:32:36 by ptungbun          #+#    #+#             */
/*   Updated: 2023/11/21 12:54:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_H
# define KAREN_H
# include <string>

class Karen {

public:
	Karen(void);
	~Karen(void);

	void	complain(std::string level);

private:
	void	_error(void);
	void	_warning(void);
	void	_info(void);
	void	_debug(void);

};

#endif
