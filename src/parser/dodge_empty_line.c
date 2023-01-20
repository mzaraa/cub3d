/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dodge_empty_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:36:19 by mzaraa            #+#    #+#             */
/*   Updated: 2023/01/20 16:33:06 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	dodge_empty_line(t_data *data, char *line)
{
	char	*trimed;

	trimed = ft_strtrim(ft_strdup(line), WHITESPACE);
	if (!*trimed)
	{
		free(trimed);
		free (data->line_gnl);
		printf("Error\nNot empty line detected\n");
		ft_exit_program(data);
	}
	if (*trimed)
		free(trimed);
	return (0);
}
