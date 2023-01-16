/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:43:36 by mzaraa            #+#    #+#             */
/*   Updated: 2023/01/16 12:22:00 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data(t_data *data)
{
	ft_memset(data, 0, sizeof(t_data));
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
	return (0);
}
