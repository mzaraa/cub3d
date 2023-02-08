#include "cub3d.h"

int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char    *pixel;

    pixel = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(int *)pixel = color;
}

int render_rectangle(t_img *img, t_rect rect)
{
	int	i;
	int j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			my_pixel_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

int	render(t_data *data)
{
	int i = 0;
	int j = 0;
	int ratio = 0;

	if (data->win_ptr == NULL)
		return (1);
	// compute the perimeter of the rectangle for each value of the map with the size of the window and the size of the map
	ratio = (WINDOW_WIDTH / data->map_width) < (WINDOW_HEIGHT / data->map_height) ? (WINDOW_WIDTH / data->map_width) : (WINDOW_HEIGHT / data->map_height);
	// draw the map with 1 = red and 0 = green and NSEW = blue
	while ( i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (data->map[i][j] == '1')
				render_rectangle(&data->img, (t_rect){j * ratio, i * ratio, ratio-1, ratio-1, RED_PIXEL});
			else
				render_rectangle(&data->img, (t_rect){j * ratio, i * ratio, ratio-1, ratio-1, GREEN_PIXEL});
			j++;
		}
		i++;
	}
	return (0);
}