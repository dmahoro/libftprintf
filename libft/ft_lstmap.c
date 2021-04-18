/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 23:20:55 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/04/03 00:38:13 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*front;
	t_list	*newlst;

	if (lst)
	{
		current = lst;
		front = ft_lstnew(f(current->content));
		if (!front)
			return (NULL);
		current = current->next;
		while (current)
		{
			newlst = ft_lstnew(f(current->content));
			if (!newlst)
			{
				ft_lstclear(&front, del);
				return (NULL);
			}
			ft_lstadd_front(&front, newlst);
			current = current->next;
		}
		return (front);
	}
	return (NULL);
}
