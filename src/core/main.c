/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:43:36 by mzaraa            #+#    #+#             */
/*   Updated: 2023/01/18 19:16:30 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data(t_data *data)
{
	ft_memset(data, 0, sizeof(t_data));
	data->id_tab = malloc(sizeof(t_elements) * TOTAL);
	ft_memset(data->id_tab, 0, sizeof(t_elements) * TOTAL);
	data->state = INIT;
	data->all_id_present = 63;
	data->map_list = NULL;
}

int	main(int ac, char **av)
{
	t_data	*data;
	int i = 0;

	if (ac != 2 || !check_file_name(av[1]))
	{
		printf("%sError%s\nUsage => ./cub3D <filename> + .cub\n", KRED, RST);
		exit (EXIT_FAILURE);
	}
	data = malloc(sizeof(t_data));
	init_data(data);
	parser(data, av[1]);
	while (i < 6)
	{
		if (i < 4 && data->id_tab[i].info_tex != NULL)
			printf("%s\n", data->id_tab[i].info_tex);
		else if (data->id_tab[i].info_rgb != NULL)
			printf("%d %d %d\n", data->id_tab[i].info_rgb[0], data->id_tab[i].info_rgb[1], data->id_tab[i].info_rgb[2]);
		i++;
	}
	while (data->map_list)
	{
		printf("%s", data->map_list->content);
		data->map_list = data->map_list->next;
	}
	return (0);
}
