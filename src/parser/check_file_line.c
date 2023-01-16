/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:24:53 by mzaraa            #+#    #+#             */
/*   Updated: 2023/01/16 17:17:20 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_line(t_data *data, char *line)
{
	const t_tuple	tab[] = {{"NO", NO}, {"SO", SO}, {"WE", WE}, {"EA", EA},
	{"F", F}, {"C", C}, {NULL, TOTAL}};
	unsigned int	i;
	char			*temp;

	i = 0;
	temp = line;
	while (!ft_isalpha(temp[i]))
		i++;
	while (tab[i].id_str)
	{
		if (ft_strncmp(line, tab[i].id_str, 2) == 0)
		{
			check_double(data, tab[i].enum_v, line);
			if (tab[i].enum_v == F || tab[i].enum_v == C)
				data->id_tab[tab[i].enum_v].info_rgb = parse_rgb(data, line);
			else
			{
				data->id_tab[tab[i].enum_v].info_texture = \
				parse_texture(data, line);
			}
		}
		i++;
	}
	return (0);
}
