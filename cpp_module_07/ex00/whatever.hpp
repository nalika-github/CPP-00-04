/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:01:52 by ptungbun          #+#    #+#             */
/*   Updated: 2024/02/25 20:50:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename Type>
void	swap(Type &a, Type &b)
{
	Type buf;
	buf = b;
	b = a;
	a = buf;
}

template <typename Type>
Type	max(Type x, Type y)
{
	return (x > y) ? x : y;
}

template <typename Type>
Type	min(Type x, Type y)
{
	return (x > y) ? y : x;
}

#endif
