/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 00:15:37 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/04/02 01:46:16 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	char	seps[2];
	char	*str;

	str = (char *)s;
	seps[0] = c;
	return (ft_split_set_separators(str, seps));
}
