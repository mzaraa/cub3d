/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_identifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:22:35 by mzaraa            #+#    #+#             */
/*   Updated: 2023/01/18 18:16:31 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*trim_line(t_data *data, char *line)
{
	char	*trimed;

	trimed = ft_strtrim(line, WHITESPACE);
	// printf("trimed: %s\n", trimed);
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
	char	*line;
	char	*trimed;

	line = NULL;
	trimed = NULL;
	while (data->present_id != data->all_id_present)
	{
		line = gnl(fd);
		if (line == NULL)
			break ;
		else if (line[0] == '\n')
		{
			free (line);
			continue ;
		}
		trimed = trim_line(data, line);
		check_line(data, trimed);
		free(line);
		free(trimed);
	}
	if (data->present_id == data->all_id_present)
		return (1);
	return (0);
}
