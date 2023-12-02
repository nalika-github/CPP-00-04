/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:12:28 by ptungbun          #+#    #+#             */
/*   Updated: 2023/12/02 01:36:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed {

public:

	Fixed(void);
	Fixed(Fixed const &src);
	~Fixed(void);

	Fixed &	operator = (Fixed const & src);

	int		getRawBits(void) const;
	void	setRawBits(int const RawBits);

private:

	int	_fixed_point;
	static const int _fractional_bit = 8;
};

#endif
