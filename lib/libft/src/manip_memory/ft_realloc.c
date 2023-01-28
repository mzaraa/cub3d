/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:54:19 by mzaraa            #+#    #+#             */
/*   Updated: 2023/01/27 16:52:32 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t size)
{
	void	*new_ptr;

	new_ptr = malloc((size + 1));
	if (ptr)
	{
		ft_bzero(new_ptr, size + 1);
		ft_memcpy(new_ptr, ptr, size + 1, old_size);
		free(ptr);
	}
	return (new_ptr);
}
