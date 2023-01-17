/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_identifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:22:35 by mzaraa            #+#    #+#             */
/*   Updated: 2023/01/17 18:31:46 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_identifier(t_data *data, int fd)
{
	char	*line;

	line = NULL;
	while (data->present_id != data->all_id_present)
	{
		line = gnl(fd);
		printf("present_id: %zu\n", data->present_id);
		if (line == NULL)
			break ;
		else if (line[0] == '\n')
		{
			free (line);
			continue ;
		}
		else if ((line[0] == ' ' || line[0] == '\t') && data->present_id != 63)
		{
			free(line);
			perror("Error: Identifier not at the beginning of the line");
			ft_exit_program(data);
		}
		printf("line: %s", line);
		check_line(data, line);
		free(line);
	}
	if (data->present_id == data->all_id_present)
		return (1);
	return (0);
}
