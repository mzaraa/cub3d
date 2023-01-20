/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_identifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:22:35 by mzaraa            #+#    #+#             */
/*   Updated: 2023/01/20 15:30:49 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*trim_line(t_data *data, char *line)
{
	char	*trimed;

	trimed = ft_strtrim(line, WHITESPACE);
	if ((ft_isspace(line[0]) && !*trimed) && data->present_id != 63)
	{
		free(line);
		printf("Error\nNot empty line detected\n");
		ft_exit_program(data);
	}
	return (trimed);
}

int	parse_identifier(t_data *data, int fd)
{
	char	*trimed;

	data->line_gnl = NULL;
	trimed = NULL;
	while (data->present_id != data->all_id_present)
	{
		data->line_gnl = gnl(fd);
		if (data->line_gnl == NULL)
			break ;
		else if (data->line_gnl[0] == '\n')
		{
			free (data->line_gnl);
			continue ;
		}
		trimed = trim_line(data, data->line_gnl);
		check_line(data, trimed);
		free(data->line_gnl);
		free(trimed);
	}
	if (data->present_id == data->all_id_present)
		return (1);
	return (0);
}
