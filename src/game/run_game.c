/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:06:54 by mzaraa            #+#    #+#             */
/*   Updated: 2023/02/06 14:05:56 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_destroy_mlx(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
	ft_exit_program(data, "Exit program");
}

void	run_game(t_data *data)
{
    
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		ft_exit_program(data, "Error\nmlx_init() failed");
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D");
	if (!data->win_ptr)
		ft_exit_program(data, "Error\nmlx_new_window() failed");
    data->img.mlx_img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
    if (!data->img.mlx_img)
        ft_exit_program(data, "Error\nmlx_new_image() failed");
    data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, &data->img.line_length, &data->img.endian);
	if (!data->img.addr)
		ft_exit_program(data, "Error\nmlx_get_data_addr() failed");
	mlx_loop_hook(data->mlx_ptr, &render, data);
	mlx_hook(data->win_ptr, 3, (1L<<1), key_release, data);
	mlx_hook(data->win_ptr, 2, (1L<<0), key_press, data);
	mlx_hook(data->win_ptr, 17, 0, close_window, data);
	mlx_loop(data->mlx_ptr);
}
