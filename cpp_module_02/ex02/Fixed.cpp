/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:12:22 by ptungbun          #+#    #+#             */
/*   Updated: 2023/11/25 21:57:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixed_point(0)
{
}

Fixed::Fixed(int const n) : _fixed_point(n << _fractional_bit)
{
}

Fixed::Fixed(float const n) : _fixed_point(roundf(n * (1 << _fractional_bit)))
{
}

Fixed::Fixed(Fixed const &src)
{
	*this = src;
}

Fixed::~Fixed(void)
{
}

Fixed &Fixed::operator = (Fixed const &src)
{
	if (this != &src)
		this->_fixed_point = src.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	return (this->_fixed_point);
}

void	Fixed::setRawBits(int const RawBits)
{
	this->_fixed_point = RawBits;
}

float	Fixed::toFloat(void) const
{
	return ((float)(this->_fixed_point) / (float)(1 << _fractional_bit));
}

int		Fixed::toInt(void) const
{
	return (this->_fixed_point >> _fractional_bit);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a.toFloat() <= b.toFloat())
		return (a);
	else
		return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() <= b.toFloat())
		return (a);
	else
		return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a.toFloat() >= b.toFloat())
		return (a);
	else
		return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() >= b.toFloat())
		return (a);
	else
		return (b);
}

std::ostream & operator << (std::ostream &ost, Fixed const &i)
{
	ost << i.toFloat();
	return (ost);
}

bool	Fixed::operator > (Fixed src) const
{
	return (this->toFloat() > src.toFloat());
}

bool	Fixed::operator < (Fixed src) const
{
	return (this->toFloat() < src.toFloat());
}

bool	Fixed::operator >= (Fixed src) const
{
	return (this->toFloat() >= src.toFloat());
}

bool	Fixed::operator <= (Fixed src) const
{
	return (this->toFloat() <= src.toFloat());
}

bool	Fixed::operator == (Fixed src) const
{
	return (this->toFloat() == src.toFloat());
}

bool	Fixed::operator != (Fixed src) const
{
	return (this->toFloat() != src.toFloat());
}

float	Fixed::operator + (Fixed src) const
{
	return (this->toFloat() + src.toFloat());
}

float	Fixed::operator - (Fixed src) const
{
	return (this->toFloat() - src.toFloat());
}

float	Fixed::operator * (Fixed src) const
{
	return (this->toFloat() * src.toFloat());
}

float	Fixed::operator / (Fixed src) const
{
	return (this->toFloat() / src.toFloat());
}


Fixed	Fixed::operator ++ ()
{
	this->_fixed_point++;
	return (*this);
}

Fixed	Fixed::operator -- ()
{
	this->_fixed_point--;
	return (*this);
}

Fixed	Fixed::operator ++ (int)
{
	Fixed tmp = *this;
	++this->_fixed_point;
	return (tmp);
}

Fixed	Fixed::operator -- (int)
{
	Fixed tmp = *this;
	--this->_fixed_point;
	return (tmp);
}
