/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:50:13 by qdo               #+#    #+#             */
/*   Updated: 2024/03/12 16:04:45 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_sstr_re(char *s, size_t len)
{
	char	*sstr;

	sstr = (char *)malloc((len +1) * sizeof(char));
	if (sstr == 0)
		return (NULL);
	sstr[len] = 0;
	while (len > 0)
	{
		sstr[len - 1] = s[len - 1];
		len --;
	}
	return (sstr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		cnt;

	cnt = ft_strlen((char *)s);
	if (cnt < (size_t)start)
		return (ft_sstr_re((char *)(s + start), 0));
	if (cnt >= len + (size_t)start)
		return (ft_sstr_re((char *)(s + start), len));
	else
		return (ft_sstr_re((char *)(s + start), cnt - (int)start));
}
//line 49: it's cnt - start >= len.

// int	main(void)
// {
// 	printf("%s\n",ft_substr("",0, 5));
// }
