/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:56:14 by mzaraa            #+#    #+#             */
/*   Updated: 2023/02/18 14:57:57 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wall(t_data *data, int color)
{
	int	y;

	y = data->ray.draw_start;
	while (y < data->ray.draw_end)
	{
		my_pixel_put(&data->img, data->ray.x, y, color);
		y++;
	}
}

void	wall_tex(t_data *data, int tex_num)
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
	if ((data->ray.side == 0 && data->ray.ray_dir.x > 0) || \
		(data->ray.side == 1 && data->ray.ray_dir.y < 0))
		tex_x = (int)((double)data->tex_img[tex_num].width - tex_x - 1);
	step = 1.0 * data->tex_img[tex_num].height / data->ray.line_height;
	tex_pos = (data->ray.draw_start - WINDOW_HEIGHT / 2 - data->ray.line_height / 2) * step;
	while (data->ray.draw_start < data->ray.draw_end)
	{
		int tex_y = (int)tex_pos & (data->tex_img[tex_num].height - 1);
		tex_pos += step;
		uint32_t color = (int)data->tex_img[tex_num].addr[data->tex_img[tex_num].height * tex_y + tex_x];
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
