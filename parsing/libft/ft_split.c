/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:59:48 by qdo               #+#    #+#             */
/*   Updated: 2024/05/08 01:34:49 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_ret_len(char *dup, size_t dup_len)
{
	int	i;
	int	j;
	int	cnt;

	cnt = 0;
	j = 0;
	i = 0;
	while (dup_len > 0)
	{
		if (*dup)
			i = 1;
		else
			i = 0;
		if (i != j && i == 1)
			cnt++;
		j = i;
		dup++;
		dup_len--;
	}
	return (cnt);
}

static void	ft_new_dup(char *dup, size_t dup_full_len, char *separators)
{
	int	i;

	while (dup_full_len > 0)
	{
		i = -1;
		while (separators[++i])
		{
			if (*dup == separators[i])
				*dup = 0;
		}
		dup++;
		dup_full_len--;
	}
	return ;
}

static char	**ft_free(char **ret, int ret_i, char *dup, int c)
{
	if (c == 0)
	{
		while (ret_i >= 0)
		{
			free(ret[ret_i]);
			ret_i--;
		}
		free(ret);
	}
	else
		free(dup);
	return (NULL);
}

static char	**fill(char **ret, char *dup, size_t dup_full_len)
{
	int	ret_i;

	ret_i = 0;
	while (dup_full_len > 0)
	{
		if (*dup)
		{
			ret[ret_i] = ft_strdup(dup);
			if (ret[ret_i] == 0)
			{
				ft_free(ret, ret_i - 1, dup, 0);
				return (0);
			}
			ret_i++;
			dup_full_len = dup_full_len - ft_strlen(dup);
			dup = dup + ft_strlen(dup);
		}
		else
		{
			dup_full_len--;
			dup++;
		}
	}
	return (ret);
}

//1. dup s
//2. len of dup.
//3. which character of dup exist in c, change it to 0.
//4. Count how many substring we  need (ret_len)
//5. fill them
//6. Null terminated and return
char	**ft_split(char const *s, char *separators)
{
	size_t	dup_full_len;
	size_t	ret_len;
	char	**ret;
	char	*dup;

	if (separators == NULL)
		return (0);
	dup = ft_strdup((char *)s);
	if (dup == 0)
		return (0);
	dup_full_len = ft_strlen(dup);
	ft_new_dup(dup, dup_full_len, separators);
	ret_len = ft_ret_len(dup, dup_full_len);
	ret = (char **)malloc((ret_len + 1) * sizeof(char *));
	if (ret == 0)
		return (ft_free(ret, 0, dup, 1));
	ret = fill(ret, dup, dup_full_len);
	if (ret == 0)
		return (ft_free(ret, 0, dup, 1));
	ret[ret_len] = 0;
	free(dup);
	return (ret);
}
