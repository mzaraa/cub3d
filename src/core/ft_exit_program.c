/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_program.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:51:47 by mzaraa            #+#    #+#             */
/*   Updated: 2023/01/18 18:15:09 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// todo : free all the data
void	ft_exit_program(t_data *data)
{
	(void)data;
	if (data->id_tab)
		free(data->id_tab);
	if (data->map_list)
		ft_lstclear(&data->map_list, free);
	// printf("Exiting program");
	exit(0);
}
