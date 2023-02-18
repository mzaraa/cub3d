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

void init_xpm(t_data *data)
{
	t_img	*img;
	int		i;

	i = 0;
	while (i < 4)
	{
		img = &data->tex_img[i];
		img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, \
			data->id_tab[i].info_tex, &img->width, &img->height);
		if (!img->mlx_img)
			ft_exit_program(data, "Error\nmlx_xpm_file_to_image() failed");
		img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp, \
			&img->line_length, &img->endian);
		if (!img->addr)
			ft_exit_program(data, "Error\nmlx_get_data_addr() failed");
		i++;
	}
}

void	wall(t_data *data, int color)
{
	int	y;

	y = data->ray.draw_start;
	// printf("draw_start: %d\n", data->ray.draw_start);
	while (y < data->ray.draw_end)
	{
		my_pixel_put(&data->img, data->ray.x, y, color);
		y++;
	}
}

void wall_tex(t_data *data, int tex_num)
{
	double	wall_x;
	int		tex_x;
	double	step;
	double	tex_pos;

	if (data->ray.side == 0)
		wall_x = data->player.pos.y + data->ray.perp_wall_dist * data->ray.ray_dir.y;
	else
		wall_x = data->player.pos.x + data->ray.perp_wall_dist * data->ray.ray_dir.x;
	wall_x -= floor((wall_x));
	tex_x = (int)(wall_x * (double)data->tex_img[tex_num].width);
	if (data->ray.side == 0 && data->ray.ray_dir.x > 0)
		tex_x = (int)((double)data->tex_img[tex_num].width - tex_x - 1);
	if (data->ray.side == 1 && data->ray.ray_dir.y < 0)
		tex_x = (int)((double)data->tex_img[tex_num].width - tex_x - 1);  
	step = 1.0 * data->tex_img[tex_num].height / data->ray.line_height;
	tex_pos = (data->ray.draw_start - WINDOW_HEIGHT / 2 + data->ray.line_height / 2) * step;
	while (data->ray.draw_start < data->ray.draw_end)
	{
		int tex_y = (int)tex_pos & (data->tex_img[tex_num].height - 1);
		tex_pos += step;
		uint32_t color = data->tex_img[tex_num].addr[data->tex_img[tex_num].height * tex_y + tex_x];
		if (data->ray.side == 1)
			color = (color >> 1) & 8355711;
		my_pixel_put(&data->img, data->ray.x, data->ray.draw_start, color);
		data->ray.draw_start++;
	}
}

void	draw_wall(t_data *data)
{
	data->ray.line_height = (int)(WINDOW_HEIGHT / data->ray.perp_wall_dist);
	data->ray.draw_start = (-data->ray.line_height) / 2 + WINDOW_HEIGHT / 2;

	if (data->ray.draw_start < 0)
		data->ray.draw_start = 0;
	data->ray.draw_end = data->ray.line_height / 2 + WINDOW_HEIGHT / 2;
	if (data->ray.draw_end >= WINDOW_HEIGHT)
		data->ray.draw_end = WINDOW_HEIGHT - 1;
	
	if (data->map[data->ray.map.y][data->ray.map.x] == '1')
	{
		if (data->test == NO)
	 		wall_tex(data, NO);
		else if (data->test == SO)
			wall_tex(data, SO);
		else if (data->test == WE)
			wall_tex(data, WE);
		else if (data->test == EA)
			wall_tex(data, EA);
	}
}

void	run_game(t_data *data)
{
    
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		ft_exit_program(data, "Error\nmlx_init() failed");
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D");
	if (!data->win_ptr)
		ft_exit_program(data, "Error\nmlx_new_window() failed");
	init_xpm(data);
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
