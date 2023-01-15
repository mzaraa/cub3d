/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 09:44:02 by mzaraa            #+#    #+#             */
/*   Updated: 2023/01/14 12:33:05 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// converti avec ascii une string en int
int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	neg = 1;
	res = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			neg *= -1;
	while (str[i] >= '0' && str[i] <= '9')
		res = (str[i++] - '0') + (res * 10);
	return (res * neg);
}

// int	main(void)
// {
// 	char *s = "12147483647";

// 	printf("%d %d", ft_atoi(s), atoi(s));
// 	return (0);
// }
