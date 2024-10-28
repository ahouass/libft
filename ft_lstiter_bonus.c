/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouass <ahouass@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:51:42 by ahouass           #+#    #+#             */
/*   Updated: 2024/10/28 15:09:54 by ahouass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;

	if (lst != NULL && !f)
		return ;
	tmp = lst;
	while (tmp != NULL)
	{
		f(tmp->content);
		tmp = tmp->next;
	}
}
