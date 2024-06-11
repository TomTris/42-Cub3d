/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:02:25 by qdo               #+#    #+#             */
/*   Updated: 2024/03/11 15:10:52 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	char	*a;
	size_t	n;

	ptr = (void *)malloc(count * size);
	if (ptr == 0)
		return (NULL);
	a = (char *)ptr;
	while (count > 0 && size > 0)
	{
		n = size;
		while (n > 0)
		{
			*a++ = 0;
			n--;
		}
		count--;
	}
	return (ptr);
}

// int	main(void)
// {
// 		printf("%s\n",ft_calloc(10,0));
// 	return (0);
// }
