/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set_separators.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:08:41 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/04/02 04:05:07 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_fillword(char *str, size_t i, char *charset)
{
	size_t	len_str;
	size_t	j;
	char	*res_str;

	len_str = ft_firstwordlen(str, i, charset);
	res_str = (char *)malloc(sizeof(char) * (len_str + 1));
	if (!res_str)
		return (NULL);
	j = 0;
	while (j < len_str)
		res_str[j++] = str[i++];
	res_str[j] = '\0';
	return (res_str);
}

static char	**ft_splitstr(char *str, char *charset, char **res_str)
{
	size_t	i;
	size_t	k;
	char	set_map[32];

	i = 0;
	k = 0;
	ft_bit_map(set_map, 32, charset);
	while (str[i])
	{
		if (!ft_bit_at(set_map, str[i]))
		{
			res_str[k] = ft_fillword(str, i, charset);
			if (!res_str[k])
				return (NULL);
			i = i + ft_strlen(res_str[k++]);
		}
		else
			i++;
	}
	res_str[k] = NULL;
	return (res_str);
}

char	**ft_split_set_separators(char *str, char *charset)
{
	char	**res_str;
	size_t	n_words;

	n_words = ft_countwords(str, charset);
	res_str = (char **)malloc(sizeof(char *) * (n_words + 1));
	if (!res_str)
		return (NULL);
	return (ft_splitstr(str, charset, res_str));
}
