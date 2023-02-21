/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:56:14 by mzaraa            #+#    #+#             */
/*   Updated: 2023/02/21 11:52:53 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wall(t_data *data, int color)
{
	int	y;

	y = data->ray.draw_s;
	while (y < data->ray.draw_e)
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
	int		tex_y;

	if (data->ray.side == 0)
		wall_x = data->player.pos.y + data->ray.pwd * data->ray.ray_dir.y;
	else
		wall_x = data->player.pos.x + data->ray.pwd * data->ray.ray_dir.x;
	wall_x -= floor((wall_x));
	tex_x = (int)(wall_x * (double)data->tex_img[tex_num].width);
	if ((data->ray.side == 0 && data->ray.ray_dir.x > 0) || \
		(data->ray.side == 1 && data->ray.ray_dir.y < 0))
		tex_x = (int)((double)data->tex_img[tex_num].width - tex_x - 1);
	step = 1.0 * data->tex_img[tex_num].height / data->ray.l_height;
	tex_pos = (data->ray.draw_s - HEIGHT / 2 - data->ray.l_height / 2) * step;
	while (data->ray.draw_s < data->ray.draw_e)
	{
		tex_y = (int)tex_pos & (data->tex_img[tex_num].height - 1);
		tex_pos += step;
		my_pixel_put(&data->img, data->ray.x, data->ray.draw_s, \
			data->tex[tex_num][data->tex_img[tex_num].height * tex_y + tex_x]);
		data->ray.draw_s++;
	}
}

void	draw_wall(t_data *data)
{
	data->ray.l_height = (int)(HEIGHT / data->ray.pwd);
	data->ray.draw_s = (-data->ray.l_height) / 2 + HEIGHT / 2;
	if (data->ray.draw_s < 0)
		data->ray.draw_s = 0;
	data->ray.draw_e = data->ray.l_height / 2 + HEIGHT / 2;
	if (data->ray.draw_e >= HEIGHT)
		data->ray.draw_e = HEIGHT - 1;
	if (data->map[data->ray.map.y][data->ray.map.x] == '1')
	{
		if (data->tex_to_draw == NO)
			wall_tex(data, NO);
		else if (data->tex_to_draw == SO)
			wall_tex(data, SO);
		else if (data->tex_to_draw == WE)
			wall_tex(data, WE);
		else if (data->tex_to_draw == EA)
			wall_tex(data, EA);
	}
}
