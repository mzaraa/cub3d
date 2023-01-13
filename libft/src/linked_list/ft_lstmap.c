/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:23:31 by mzaraa            #+#    #+#             */
/*   Updated: 2021/11/13 14:01:30 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Itère sur la liste lst et applique la fonction f au contenu de chaque élément. 
Crée une nouvelle liste résultant des applications successives de f. 
la fonction del est la pour detruire le contenu d un element si necessaire.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*fresh;

	fresh = NULL;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (!new)
		{
			ft_lstclear(&fresh, del);
			return (NULL);
		}
		ft_lstadd_back(&fresh, new);
		lst = lst->next;
	}
	return (fresh);
}
