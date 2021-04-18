/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 22:47:20 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/04/02 22:53:27 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *newlst)
{
	t_list	*ite;

	if (alst)
	{
		if (!*alst)
			*alst = newlst;
		else
		{
			ite = ft_lstlast(*alst);
			ite->next = newlst;
		}
	}
}
