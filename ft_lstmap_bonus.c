/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouass <ahouass@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:59:08 by ahouass           #+#    #+#             */
/*   Updated: 2024/10/28 15:48:21 by ahouass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	if(!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while(lst != NULL)
	{
		new_node = ft_lstnew(f(lst->content));
		if(new_node)
		{
			ft_lstadd_back(&new_list, new_node);
			lst = lst->next;
		}
		else
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
	}
	return (new_list);
}