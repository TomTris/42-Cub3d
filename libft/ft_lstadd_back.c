/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:54:20 by qdo               #+#    #+#             */
/*   Updated: 2024/03/14 18:30:44 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lst1;

	if (lst == 0)
		return ;
	if ((*lst) == 0)
	{
		(*lst) = new;
		return ;
	}
	lst1 = *lst;
	while (lst1->next)
		lst1 = lst1->next;
	lst1->next = new;
}
