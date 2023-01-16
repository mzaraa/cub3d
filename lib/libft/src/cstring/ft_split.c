/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:46:32 by mzaraa            #+#    #+#             */
/*   Updated: 2023/01/16 12:19:30 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ischarset(char const c, char const *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		++charset;
	}
	return (0);
}

int	ft_strlen_s(char const *s, char const *charset)
{
	int	i;

	i = 0;
	while (*s && !ischarset(*s++, charset))
		++i;
	return (i);
}

int	nb_word(char const *s, char const *charset)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (!ischarset(*s, charset))
		{
			count++;
			while (*s && !ischarset(*s, charset))
				++s;
		}
		else
			++s;
	}
	return (count);
}

char	*ft_cpy(char const *s, char const *charset)
{
	char	*str;
	char	*strcpy;

	str = malloc(sizeof(char) * (ft_strlen_s(s, charset) + 1));
	strcpy = str;
	while (*s && !ischarset(*s, charset))
		*str++ = *s++;
	*str = '\0';
	return (strcpy);
}

char	**ft_split(char const *s, char const *charset)
{
	char	**str;
	char	**strcpy;

	if (!s || !charset)
		return (NULL);
	str = malloc(sizeof(char *) * (nb_word(s, charset) + 1));
	if (!str)
		return (NULL);
	strcpy = str;
	while (*s)
	{
		if (!ischarset(*s, charset))
		{
			*str++ = ft_cpy(s, charset);
			while (*s && !ischarset(*s, charset))
				++s;
		}
		else
			++s;
	}
	*str = 0;
	return (strcpy);
}
