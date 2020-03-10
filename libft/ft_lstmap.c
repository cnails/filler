/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 13:01:04 by cnails            #+#    #+#             */
/*   Updated: 2019/09/12 15:37:00 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *list;
	t_list *new;

	list = f(lst);
	new = list;
	if (!lst || !f)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		if (!(list->next = f(lst)))
			return (NULL);
		list = list->next;
	}
	return (new);
}
