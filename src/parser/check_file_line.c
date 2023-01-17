/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:24:53 by mzaraa            #+#    #+#             */
/*   Updated: 2023/01/17 18:08:49 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_line(t_data *data, char *line)
{
	const t_tuple	tab[] = {{"NO", NO}, {"SO", SO}, {"WE", WE}, {"EA", EA},
	{"F ", F}, {"C ", C}, {NULL, TOTAL}};
	unsigned int	i;

	i = 0;
	while (tab[i].id_str)
	{
		if (ft_strncmp(line, tab[i].id_str, 2) == 0)
		{
			printf("Function: check_line \n");
			check_double(data, tab[i].enum_v, line);
			data->id_tab[tab[i].enum_v].id = ft_strdup(tab[i].id_str);
			if (tab[i].enum_v == F || tab[i].enum_v == C)
				data->id_tab[tab[i].enum_v].info_rgb = parse_rgb(data, line);
			else
				data->id_tab[tab[i].enum_v].info_tex = parse_tex(data, line);
			return ;
		}
		i++;
	}
	perror("Error: Invalid identifier");
	if (*line)
		free(line);
	ft_exit_program(data);
}
