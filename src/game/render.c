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
	int r;
	int g;
	int b;
	ft_memset(data->img.addr, 0, data->img.line_length * data->img.height);
	key_manager(data);
	r = data->id_tab[F].info_rgb[0];
	g = data->id_tab[F].info_rgb[1];
	b = data->id_tab[F].info_rgb[2];
	if (data->win_ptr == NULL)
		return (1);
	// draw the background
	render_rectangle(&data->img, (t_rect){0, 0, WINDOW_WIDTH, WINDOW_HEIGHT/2, encode_rgb(r, g, b)});
	r = data->id_tab[C].info_rgb[0];
	g = data->id_tab[C].info_rgb[1];
	b = data->id_tab[C].info_rgb[2];
	render_rectangle(&data->img, (t_rect){0, WINDOW_HEIGHT/2, WINDOW_WIDTH, WINDOW_HEIGHT/2, encode_rgb(r, g, b)});
	raycast(data);
	data->ray.x = 0;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}