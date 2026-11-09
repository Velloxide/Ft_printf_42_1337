/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saboutay <saboutay@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 22:55:44 by saboutay          #+#    #+#             */
/*   Updated: 2026/10/20 23:53:45 by saboutay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_clear_map(t_list **lst, void *upcontent,
		void (*del)(void *))
{
	if (upcontent)
		del(upcontent);
	ft_lstclear(lst, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*newnode;
	void	*upcontent;

	if (!lst || !f || !del)
		return (NULL);
	newlist = NULL;
	while (lst)
	{
		upcontent = f(lst->content);
		if (!upcontent)
			return (ft_clear_map(&newlist, upcontent, del));
		newnode = ft_lstnew(upcontent);
		if (!newnode)
			return (ft_clear_map(&newlist, upcontent, del));
		ft_lstadd_back(&newlist, newnode);
		lst = lst->next;
	}
	return (newlist);
}
