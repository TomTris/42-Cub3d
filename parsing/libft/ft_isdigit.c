/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 22:39:22 by qdo               #+#    #+#             */
/*   Updated: 2024/03/06 14:52:41 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int a)
{
	if ((a < 58) && (a > 47))
		return (1);
	else
		return (0);
}
/*int main(void)
{
    int a;

    a = 0;
    while(a < 170)
    {
        if ((ft_isdigit(a)) != (isdigit(a)))
        {
            printf("%d",a);
            break;
        }
        a++;
    }
    if (a == 170)
        printf("%d", a);
    return(0);
}*/