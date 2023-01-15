/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:43:36 by mzaraa            #+#    #+#             */
/*   Updated: 2023/01/13 10:13:22 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->state = INIT;
	if (ac != 2 || !check_file_name(av[1]))
	{
		printf("Error in arguments\n");
		return (0);
	}
	parser(data, av[1]);
	return (0);
}
