/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:45:57 by mzaraa            #+#    #+#             */
/*   Updated: 2023/01/17 16:58:38 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_map(t_data *data)
{
	t_list	*tmp;
	int		i;

	tmp = data->map_list;
	i = ft_lstsize(data->map_list);
	data->map = (char **)malloc(sizeof(char *) * (i + 1));
	if (data->map == NULL)
	{
		perror("Error: Malloc failed");
		ft_exit_program(data);
	}
	i = 0;
	while (tmp)
	{
		data->map[i] = ft_strdup(tmp->content);
		tmp = tmp->next;
		i--;
	}
	data->map[i] = NULL;
	ft_lstclear(&data->map_list, free);
}
