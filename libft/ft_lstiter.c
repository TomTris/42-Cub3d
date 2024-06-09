/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:22:33 by qdo               #+#    #+#             */
/*   Updated: 2024/03/12 18:39:28 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*ptr;

	if (lst == 0)
		return ;
	while (lst->next != 0)
	{
		ptr = lst;
		lst = lst->next;
		(*f)(ptr->content);
	}
	(*f)(lst->content);
	return ;
}
