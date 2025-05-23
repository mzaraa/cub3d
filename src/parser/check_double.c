/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:43:02 by mzaraa            #+#    #+#             */
/*   Updated: 2023/01/21 12:15:03 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Check if the identifier has already been parsed
*/
void	check_double(t_data *data, size_t id, char *line)
{
	if (data->present_id & (1 << id))
	{
		if (line)
			free(line);
		ft_exit_program(data, "Error\nDouble identifier");
	}
	data->present_id |= (1 << id);
}
