/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:48:49 by mzaraa            #+#    #+#             */
/*   Updated: 2023/01/21 12:25:11 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parser(t_data *data, char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_exit_program(data, "Error\nOpening file failed");
	}
	if (parse_identifier(data, fd))
	{
		data->line_gnl = NULL;
		parse_raw_map(data, fd);
		check_map(data);
		fill_map(data);
	}
	else
	{
		ft_exit_program(data, "Error\nMissing information");
		close(fd);
	}
	close(fd);
}
