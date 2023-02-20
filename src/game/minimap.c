#include "cub3d.h"

void draw_map(t_data *data)
{
	int i;
	int j;
	int color;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (data->map[i][j] == '1')
				color = 0x00FF0000;
			else
				color = 0x00000000;
			render_rectangle(&data->img, (t_rect){j * 10, i * 10, 10, 10, color});
			++j;
		}
		++i;
	}
}

void draw_player(t_data *data)
{
	int color;

	color = 0x0000FF00;
	// render_rectangle(&data->img, (t_rect){data->player.pos.x * 10, 
	// 	data->player.pos.y * 10, 5, 5, color});
	// draw player and center it
	render_rectangle(&data->img, (t_rect){data->player.pos.x * 10 - 5, \
		data->player.pos.y * 10 - 5, 10, 10, color});
}

int	max_of(int dx, int dy)
{
	if (dy < dx)
		return (dx);
	return (dy);
}

void	render_rays(t_data *data, t_point from, t_point to, int color)
{
	double	x_incr;
	double	y_incr;
	int		steps;

	if ((from.x < 0 || from.x >= WIDTH || from.y < 0 || from.y >= HEIGHT)
		&& (to.x < 0 || to.x >= WIDTH || to.y < 0 || to.y >= HEIGHT))
		return ;
	x_incr = to.x - from.x;
	y_incr = to.y - from.y;
	steps = max_of(ceil(fabs(x_incr)), ceil(fabs(y_incr)));
	x_incr /= steps;
	y_incr /= steps;
	while (1)
	{
		my_pixel_put(&data->img, from.x, from.y, color);
		from.x += x_incr;
		from.y += y_incr;
		if (data->map[(int)from.y / 10][(int)from.x / 10] == '1')
			break ;
		if (from.x < 0 || from.x >= WIDTH || from.y < 0 || from.y >= HEIGHT)
			break ;
	}
}

void draw_rays(t_data *data)
{
	int i;
	int color;

	i = 0;
	color = 0x00FFFFFF;
	while (i < WIDTH)
	{
		if (WIDTH / 2 - i < 0)
			color = 0x0000FFFF;
		else
			color = 0x00FFFFFF;
		render_rays(data, (t_point){data->player.pos.x * 10, \
			data->player.pos.y * 10}, \
			(t_point){data->rays_coords[i].x * 10, \
			data->rays_coords[i].y * 10}, color);
		++i;
	}
}


void minimap(t_data *data)
{
	draw_map(data);
	draw_player(data);
	draw_rays(data);
}