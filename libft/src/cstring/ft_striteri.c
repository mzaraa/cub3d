/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 15:18:38 by mzaraa            #+#    #+#             */
/*   Updated: 2021/11/13 13:44:07 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Applique la fonction f à chaque caractère de la chaîne de caractères transmise 
comme argument, et en passant son index comme premier argument. 
Chaque caractère est transmis par adresse à f pour être modifié si nécessaire.
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s && *s)
		(*f)(i++, s++);
}
