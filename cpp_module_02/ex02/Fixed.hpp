/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:12:28 by ptungbun          #+#    #+#             */
/*   Updated: 2023/11/25 19:25:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath>

class Fixed {

	public:

		Fixed(void);
		Fixed(int const n);
		Fixed(float const n);
		Fixed(Fixed const &src);
		~Fixed(void);

		Fixed &operator = (Fixed const & src);

		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(Fixed const &a, Fixed const &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(Fixed const &a, const Fixed &b);

		bool operator > (Fixed src)const;
		bool operator < (Fixed src)const;
		bool operator >= (Fixed src)const;
		bool operator <= (Fixed src)const;
		bool operator == (Fixed src)const;
		bool operator != (Fixed src)const;

		float operator + (Fixed src)const;
		float operator - (Fixed src)const;
		float operator * (Fixed src)const;
		float operator / (Fixed src)const;

		Fixed operator ++ ();
		Fixed operator -- ();
		Fixed operator ++ (int);
		Fixed operator -- (int);

		float	toFloat(void) const;
		int		toInt(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const RawBits);

	private:

		int	_fixed_point;
		static const int _fractional_bit = 8;
};

std::ostream & operator << (std::ostream &o, Fixed const & i);

#endif
