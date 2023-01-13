/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 18:40:53 by mzaraa            #+#    #+#             */
/*   Updated: 2021/11/01 17:35:26 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*chr;

	i = 0;
	chr = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			chr = (char *)(s + i);
		i++;
	}
	if (s[i] == (char)c)
		chr = (char *)(s + i);
	return (chr);
}
