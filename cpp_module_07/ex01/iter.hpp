/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:31:21 by ptungbun          #+#    #+#             */
/*   Updated: 2024/02/24 19:25:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template <typename Type> void	iter(Type *array, int length, void (*f)(Type &))
{
	for (int i = 0; i < length; i++)
		f(array[i]);
}

#endif
