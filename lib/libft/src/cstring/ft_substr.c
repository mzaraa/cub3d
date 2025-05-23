/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:45:30 by mzaraa            #+#    #+#             */
/*   Updated: 2023/01/14 12:39:02 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Alloue et retourne une chaine de caractères issue de la chaine ’s’.
Cette nouvelle chaine commence à l’index ’start’ et a pour taille maximale ’len’
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	size_t	strlen;
	char	*str;

	j = 0;
	strlen = 0;
	if (!s)
		return (0);
	if (start > (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	while (s[start + strlen] && strlen < len)
		strlen++;
	str = malloc(sizeof(char) * (strlen + 1));
	if (!str)
		return (NULL);
	while (j < strlen)
		str[j++] = s[start++];
	str[j] = '\0';
	return (str);
}
