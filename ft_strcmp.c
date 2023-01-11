/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:28:29 by mzaraa            #+#    #+#             */
/*   Updated: 2023/01/11 17:02:18 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Compares two strings and returns 0 if they are identical,
** else returns the difference between the first two different characters.
*/

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}
