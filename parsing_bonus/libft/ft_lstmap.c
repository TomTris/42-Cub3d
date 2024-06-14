/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:23:27 by qdo               #+#    #+#             */
/*   Updated: 2024/03/12 19:00:00 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew_del(void *content, void (*del)(void*))
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == 0)
	{
		del(content);
		return (NULL);
	}
	new->content = content;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void*))
{
	t_list	*ptr;
	t_list	*new;

	if ((*f) == 0 || del == 0 || lst == 0)
		return (0);
	new = ft_lstnew_del(f(lst->content), del);
	if (new == 0)
		return (0);
	ptr = new;
	lst = lst->next;
	while (lst)
	{
		ptr->next = ft_lstnew_del(f(lst->content), del);
		if (ptr->next == 0)
		{
			ft_lstclear(&new, (*del));
			return (0);
		}
		lst = lst->next;
		ptr = ptr->next;
	}
	return (new);
}
