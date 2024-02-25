/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:57:33 by ptungbun          #+#    #+#             */
/*   Updated: 2024/02/24 20:49:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename Type> Array<Type>::Array(void) : array(NULL), size(0)
{
}

template <typename Type> Array<Type>::Array(unsigned int n) : array(new Type[n]), size(n)
{
}

template <typename Type> Array<Type>::Array(const Array &prototype)
{
	array = new Type[prototype.size];
	size = prototype.size;
	for (unsigned int i = 0; i < size; i++)
		array[i] = prototype.array[i];
}

template <typename Type> Array<Type>::~Array(void)
{
	delete [] array;
}

template <typename Type> Array<Type>	&Array<Type>::&operator = (const Array &rhs)
{
	if (this != &rhs)
	{
		delete [] array;
		size = rhs.size;
		array = new Type[size];
		for (unsigned int i = 0; i < size; i++)
			array[i] = rhs.array[i];
	}
	return (*this);
}

template <typename Type> Type	&Array<Type>::&operator [] (unsigned int i)
{
	if (i >= size)
		throw std::exception();
	return (array[i]);
}

template <typename Type> unsigned int	Array<Type>::size(void) const
{
	return (size);
}
