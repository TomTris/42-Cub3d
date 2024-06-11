/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 11:38:55 by qdo               #+#    #+#             */
/*   Updated: 2024/03/12 15:55:12 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char *s1, char *s2, size_t set_cnt)
{
	int	i;

	i = 1;
	while (set_cnt > 0)
	{
		if (*s1 == *s2)
			i = 0;
		s2++;
		set_cnt--;
	}
	return (i);
}

static int	ft_check2(char *s1, char *set, size_t set_cnt)
{
	while (*s1)
	{
		if (ft_check((char *)s1, (char *)set, set_cnt) == 1)
		{
			return (1);
		}
		s1++;
	}
	return (0);
}

static size_t	ft_strtrim3(char *s1, char *set, size_t cnt, size_t set_cnt)
{
	size_t	i;

	i = 0;
	while ((cnt > 0)
		&& ((ft_check((char *)s1, (char *)set, set_cnt) == 1)
			|| ((ft_check((char *)s1, (char *)set, set_cnt) == 0)
				&& (ft_check2((char *)(s1 + 1), (char *)set, set_cnt) == 1))))
	{
		i++;
		s1++;
		cnt--;
	}
	return (i);
}

static char	*ft_strtrim2(char *s1, char *set, size_t cnt, size_t set_cnt)
{
	char	*ret;
	size_t	i;

	i = 0;
	cnt = ft_strtrim3((char *)s1, (char *)set, cnt, set_cnt);
	ret = (char *)malloc((cnt + 1) * sizeof(char));
	if (ret == 0)
		return (NULL);
	while ((cnt > 0)
		&& ((ft_check((char *)s1, (char *)set, set_cnt) == 1)
			|| ((ft_check((char *)s1, (char *)set, set_cnt) == 0)
				&& (ft_check2((char *)(s1 + 1), (char *)set, set_cnt) == 1))))
	{
		ret[i] = *s1;
		i++;
		s1++;
		cnt--;
	}
	ret[i] = 0;
	return (ret);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	cnt;
	size_t	set_cnt;

	cnt = ft_strlen((char *)s1);
	set_cnt = ft_strlen((char *)set);
	while (ft_check((char *)s1, (char *)set, set_cnt) == 0 && cnt > 0)
	{
		s1++;
		cnt--;
	}
	return (ft_strtrim2((char *)s1, (char *)set, cnt, set_cnt));
}

// int	main(void)
// {
// 	printf("%d", 1); printf(": %s\n",ft_strtrim("010010","0"));
// 	printf("%d", 2); printf(": %s\n",ft_strtrim("01023456","1"));
// 	printf("%d", 3); printf(": %s\n",ft_strtrim("01023456","6"));
// 	printf("%d", 4); printf(": %s\n",ft_strtrim("0102356",""));
// 	printf("%d", 5); printf(": %s\n",ft_strtrim("01023456"," "));
// 	printf("%d", 6); printf(": %s\n",ft_strtrim("a0102 34 56 1  ab","ab"));
// 	printf("%d", 7); printf(": %s\n",ft_strtrim("01023456",""));
// 	printf("%d", 8); printf(": %s\n",ft_strtrim("01023456","b"));
// 	printf("%d", 9); printf(": %s\n",ft_strtrim("01023456","056"));
// 	printf("%d", 10); printf(": %s\n",ft_strtrim("01023456","5"));
// 	printf("%d", 11); printf(": %s\n",ft_strtrim("","5"));
// 	return (0);
// }
