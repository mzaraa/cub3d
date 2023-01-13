/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 09:45:00 by mzaraa            #+#    #+#             */
/*   Updated: 2021/11/08 17:54:15 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// alloue de la memoire et rempli cette memoire par des zeros
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr_ma;

	ptr_ma = (void *)malloc(count * size);
	if (!ptr_ma)
		return (NULL);
	ft_bzero(ptr_ma, count * size);
	return (ptr_ma);
}
