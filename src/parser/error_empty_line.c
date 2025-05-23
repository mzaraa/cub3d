/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_empty_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:36:19 by mzaraa            #+#    #+#             */
/*   Updated: 2023/01/27 16:43:29 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_empty_line(t_data *data, char *line)
{
	char	*trimed;
	char	*tmp;

	tmp = ft_strdup(line);
	trimed = ft_strtrim(tmp, WHITESPACE);
	free(tmp);
	if (!*trimed)
	{
		free(trimed);
		free (data->line_gnl);
		ft_exit_program(data, "Error\nNot empty line detected");
	}
	if (trimed)
		free(trimed);
}
