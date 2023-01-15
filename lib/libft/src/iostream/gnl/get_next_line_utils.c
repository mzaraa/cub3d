/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 19:23:28 by mzaraa            #+#    #+#             */
/*   Updated: 2023/01/14 12:39:02 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_gnl(char *save, char *buffer)
{
	int		i;
	int		j;
	char	*str;

	str = malloc(sizeof(char) * ((ft_strlen(save) + ft_strlen(buffer)) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (save[j])
		str[i++] = save[j++];
	j = 0;
	while (buffer[j])
		str[i++] = buffer[j++];
	str[i] = '\0';
	free(save);
	return (str);
}