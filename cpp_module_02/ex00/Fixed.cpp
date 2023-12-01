/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:12:22 by ptungbun          #+#    #+#             */
/*   Updated: 2023/12/01 15:17:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixed_point(0)
{
	std::cout << "Fixed constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Fixed Copy constructor called" << std::endl;
	this->setRawBits(src.getRawBits());
}

Fixed::Fixed( int const n ) : _fixedPoint( n << _fractional_bit ) {
	std::cout << "Fixed Int constructor called" << std::endl;
}

Fixed::Fixed( float const n ) : _fixedPoint( roundf( n * ( 1 << _fractional_bit )) ) {
	std::cout << "Fixed Float constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Fixed Destructor called" << std::endl;
}

Fixed &Fixed::operator = (Fixed const &src)
{
	std::cout << "Fixed Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_fixed_point = src.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	std::cout << "Fixed getRawBits member function called" << std::endl;
	return (this->_fixed_point);
}

void	Fixed::setRawBits(int const RawBits)
{
	this->_fixed_point = RawBits;
}

int		Fixed::toInt( void ) const
{
	return this->_fixedPoint >> _fractional_bit;
}

std::ostream & operator << ( std::ostream &o, Fixed const & i ) {
	o << i.toFloat();
	return o;
}
