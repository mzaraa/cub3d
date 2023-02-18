/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:43:36 by mzaraa            #+#    #+#             */
/*   Updated: 2023/02/18 10:08:34 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data(t_data *data)
{
	ft_memset(data, 0, sizeof(t_data));
	data->id_tab = malloc(sizeof(t_elements) * TOTAL);
	ft_memset(data->id_tab, 0, sizeof(t_elements) * TOTAL);
	data->state = PARSING;
	data->all_id_present = 63;
	data->map_list = NULL;
	ft_memset(data->keys, 0, sizeof(char) * 512);
	data->ray.camera_x = 0;
	set_vector_i(&data->ray.map, 0, 0);
	data->ray.perp_wall_dist = 0;
	set_vector_i(&data->ray.step, 0, 0);
	data->ray.hit = 0;
	data->ray.side = 0;
	data->ray.x = 0;
	data->window_width = WINDOW_WIDTH;
	data->window_height = WINDOW_HEIGHT;
	data->ray.draw_start = 0;
	data->ray.draw_end = 0;
	data->ray.line_height = 0;
}

void	init_player(t_data *data)
{
	set_vector_d(&data->player.pos, data->player_pos_x + 0.5, \
		data->player_pos_y + 0.5);
	data->player.move_speed = 0.05;
	data->player.rot_speed = 0.05;
	if (data->player_dir == 'N')
		set_vector_d(&data->player.dir, 0, -1);
	else if (data->player_dir == 'S')
		set_vector_d(&data->player.dir, 0, 1);
	else if (data->player_dir == 'E')
		set_vector_d(&data->player.dir, 1, 0);
	else if (data->player_dir == 'W')
		set_vector_d(&data->player.dir, -1, 0);
	if (data->player_dir == 'N')
		set_vector_d(&data->player.plane, 0.66, 0);
	else if (data->player_dir == 'S')
		set_vector_d(&data->player.plane, -0.66, 0);
	else if (data->player_dir == 'E')
		set_vector_d(&data->player.plane, 0, 0.66);
	else if (data->player_dir == 'W')
		set_vector_d(&data->player.plane, 0, -0.66);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2 || !check_file_name(av[1]))
	{
		printf("%sError%s\nUsage => ./cub3D <filename> + .cub\n", KRED, RST);
		exit (EXIT_FAILURE);
	}
	data = malloc(sizeof(t_data));
	init_data(data);
	parser(data, av[1]);
	init_player(data);
	run_game(data);
	ft_exit_program(data, "Success");
	return (0);
}
	// print data file

	// int i = 0;
	// while (i < 6)
	// {
	// 	if (i < 4 && data->id_tab[i].info_tex != NULL)
	// 		printf("%s\n", data->id_tab[i].info_tex);
	// 	else if (data->id_tab[i].info_rgb != NULL)
	// 	printf("%d %d %d\n", data->id_tab[i].info_rgb[0], 
	// data->id_tab[i].info_rgb[1], data->id_tab[i].info_rgb[2]);
	// 	i++;
	// }
	// while (data->map_list)
	// {
	// 	printf("%s", data->map_list->content);
	// 	data->map_list = data->map_list->next;
	// }