/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:43:36 by mzaraa            #+#    #+#             */
/*   Updated: 2023/01/17 18:26:53 by mzaraa           ###   ########.fr       */
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
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2 || !check_file_name(av[1]))
	{
		printf("%sError%s: Usage => ./cub3D <filename> + .cub\n", KRED, RST);
		exit (EXIT_FAILURE);
	}
	data = malloc(sizeof(t_data));
	init_data(data);
	parser(data, av[1]);

	int i = 0;
	while (data->map[i])
	{
		printf("%s\n", data->map[i]);
		i++;
	}

	return (0);
}
