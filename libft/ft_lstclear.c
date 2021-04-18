/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 23:03:08 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/04/02 23:08:27 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **alst, void (*del)(void *))
{
	t_list	*buff;

	if (alst)
	{
		while (*alst)
		{
			buff = (*alst)->next;
			ft_lstdelone(*alst, del);
			*alst = buff;
		}
	}
}
