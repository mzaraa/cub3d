/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:48:49 by mzaraa            #+#    #+#             */
/*   Updated: 2023/01/20 16:04:49 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parser(t_data *data, char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nOpening file failed");
		ft_exit_program(data);
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
		perror("Error\nMissing information");
		ft_exit_program(data);
		close(fd);
	}
	close(fd);
}
