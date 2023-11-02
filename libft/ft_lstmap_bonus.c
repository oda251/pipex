/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 03:52:02 by yoda              #+#    #+#             */
/*   Updated: 2023/09/24 21:30:47 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*dest_start;
	t_list	*tmp;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	dest_start = ft_lstnew(f(lst->content));
	if (!dest_start)
		return (NULL);
	tmp = dest_start;
	while (lst->next)
	{
		lst = lst->next;
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&dest_start, del);
			return (NULL);
		}
		ft_lstadd_back(&tmp, new);
		tmp = tmp->next;
	}
	return (dest_start);
}
