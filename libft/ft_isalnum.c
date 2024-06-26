/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 22:50:38 by qdo               #+#    #+#             */
/*   Updated: 2024/05/10 22:04:41 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int a)
{
	if (((a > 47) && (a < 58))
		|| ((a > 64) && (a < 91))
		|| ((a > 96) && (a < 123)))
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
        if ((ft_isalnum(a)) != (isalnum(a)))
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