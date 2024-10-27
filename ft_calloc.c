/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouass <ahouass@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:32:57 by ahouass           #+#    #+#             */
/*   Updated: 2024/10/27 14:41:24 by ahouass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*p;

	if (n == 0 || size == 0)
		return (0);
	p = malloc(n * size);
	if (!p)
		return (0);
	ft_bzero(p, size * n);
	return (p);
}
#include <stdio.h>
int main()
{
	void *ptr;
	//ft_calloc(1,1);
	//ptr = calloc(641654154354, 641654154354);
	ptr = ft_calloc(641654154354, 641654154354);

}