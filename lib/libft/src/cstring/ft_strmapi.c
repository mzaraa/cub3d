/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:47:40 by mzaraa            #+#    #+#             */
/*   Updated: 2023/01/14 12:39:02 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Applique la fonction ’f’ à chaque caractère de lachaine de caractères passée 
en argument pour créer une nouvelle chaine de caractères résultant 
des applications successives de ’f’.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*strf;

	if (!s || !*f)
		return (NULL);
	strf = (char *)malloc(ft_strlen(s) + 1);
	if (!strf)
		return (NULL);
	i = 0;
	while (s[i])
	{
		strf[i] = (*f)(i, (char)s[i]);
		i++;
	}
	strf[i] = '\0';
	return (strf);
}
