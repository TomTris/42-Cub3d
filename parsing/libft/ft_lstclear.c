/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:55:27 by qdo               #+#    #+#             */
/*   Updated: 2024/03/12 18:14:01 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstclear1(t_list *lst, void (*del)(void *))
{
	if (lst->next)
		ft_lstclear1((lst->next), &(*del));
	del(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (lst == NULL)
		return ;
	if (*lst == NULL || del == 0)
	{
		lst = NULL;
		return ;
	}
	ft_lstclear1(*lst, &(*del));
	*lst = NULL;
}
