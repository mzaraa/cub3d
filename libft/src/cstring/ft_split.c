/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:46:32 by mzaraa            #+#    #+#             */
/*   Updated: 2021/11/13 13:25:36 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//compte le nombre de mots que j'aurai dans mon tableau final.
static int	ft_words_count(char const *s, char c)
{
	int	nbr_of_words;
	int	i;

	i = 0;
	nbr_of_words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			nbr_of_words++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (nbr_of_words);
}

//Copie le contenu de la source dans ma destination
char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}

//Renvoie une nouvelle chaîne de caractères qui est dupliquée (avec stncpy)
// * depuis ma string avec un maximum de n caractères.
static char	*ft_strndup(const char *s, size_t n)
{
	char	*str;

	str = (char *)malloc(n + 1);
	if (!str)
		return (NULL);
	str = ft_strncpy(str, s, n);
	str[n] = '\0';
	return (str);
}

// malloc l'espace suffisant pour accueillir 
// * les chaines de caractères fraichement separés.
char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		fresh;
	char	**str;

	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (ft_words_count(s, c)) + 1);
	if (!str)
		return ((NULL));
	i = 0;
	fresh = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
			str[fresh++] = ft_strndup(s + j, i - j);
	}
	str[fresh] = 0;
	return (str);
}
