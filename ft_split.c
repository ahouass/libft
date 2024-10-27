/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouass <ahouass@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:51:48 by ahouass           #+#    #+#             */
/*   Updated: 2024/10/26 15:31:43 by ahouass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_freeup(char **strs)
{
	int	i;

	i = 0;
	while (strs[i] != '\0')
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static int	ft_count_words(char const *str, char c)
{
	int	i;
	int	flag;
	int	counter;

	i = 0;
	flag = 1;
	counter = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			flag = 1;
		}
		if (str[i] != c && flag == 1)
		{
			flag = 0;
			counter++;
		}
		i++;
	}
	return (counter);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**arr;

	arr = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	while (i < ft_count_words(s, c))
	{
		while (s[j] == c && s[j])
			j++;
		k = j;
		while (s[j] != c && s[j])
			j++;
		arr[i] = ft_substr(s, k, j - k);
		if (!arr[i])
			return (ft_freeup(arr));
		i++;
	}
	arr[i] = 0;
	return (arr);
}
