/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 10:02:02 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/03/26 11:42:26 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	n1;
	size_t	n2;

	n1 = ft_strlen(s1);
	n2 = ft_strlen(s2);
	ret = (char *)malloc(n1 + n2 + 1);
	if (!ret)
		return (NULL);
	ret = ft_strcpy(ret, s1);
	ret = ft_strcat(ret, s2);
	ret[n1 + n2] = '\0';
	return (ret);
}
