/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:46:13 by mzaraa            #+#    #+#             */
/*   Updated: 2023/01/27 16:35:48 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Alloue et retourne une copie de la chaine ’s1’, sans les caractères spécifiés 
dans ’set’ au début et à la fin de la chaine de caractères.
*/

int	ft_inset(char c, char const *set)
{
	while (*set)
	{
		if (*set++ == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const	*s1, char const *set)
{
	char	*str;
	int		front;
	int		rear;

	front = 0;
	if (!s1)
		return (NULL);
	rear = ft_strlen(s1);
	while (ft_inset(s1[front], set))
		front++;
	while (rear > front && ft_inset(s1[rear - 1], set))
		rear--;
	str = ft_substr(s1, front, rear - front);
	if (!str)
		return (NULL);
	return (str);
}

// #include <stdio.h>

// int main()
// {
// 	printf("%s\n", ft_strtrim("abqbc", "abc"));
// 	printf("%s\n", ft_strtrim("xavocadoyz", "xyz"));
// 	return 0;
// }