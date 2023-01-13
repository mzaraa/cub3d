/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:41:03 by mzaraa            #+#    #+#             */
/*   Updated: 2021/11/13 13:52:02 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Alloue et renvoie un nouvel élément. la variable content est initialisée à 
l’aide de la valeur du paramètre content. 
La variable ’next’ est initialisée à NULL.
*/
t_list	*ft_lstnew(void *content)
{
	t_list	*ptr_fresh;

	ptr_fresh = malloc(sizeof(t_list));
	if (!ptr_fresh)
		return (NULL);
	ptr_fresh->content = content;
	ptr_fresh->next = NULL;
	return (ptr_fresh);
}
