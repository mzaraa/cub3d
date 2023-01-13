/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 09:45:53 by mzaraa            #+#    #+#             */
/*   Updated: 2021/10/26 11:05:05 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dst;
	char	*sorc;

	i = -1;
	sorc = (char *)src;
	dst = (char *)dest;
	if (!dst && !src)
		return (NULL);
	if (dest > src)
	{
		while (++i < n)
			dst[n - 1 - i] = sorc [n - 1 - i];
	}
	else
	{
		while (++i < n)
			dst[i] = sorc[i];
	}
	return (dest);
}

// int main ()
// {
//    char dest[] = "SALUTATOUS";
//    const char src[]  = "MAHMOUD";
//    char a = '6';

//    printf("Before memmove dest = %s, src = %s\n", dest, src);
//    ft_memmove(dest, src, -5);
//    printf("After memmove dest = %s, src = %s\n", dest, src);
//    return(0);
// }
