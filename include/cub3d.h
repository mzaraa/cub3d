/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:43:51 by mzaraa            #+#    #+#             */
/*   Updated: 2023/02/06 15:12:51 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "colors.h"
# include "keycode.h"
# include <stdint.h>
# include <mlx.h>

# define WHITESPACE " \t\n\v\f\r"
# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 380

# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define BLUE_PIXEL 0xFF

/*
** Represent the identifier of the elements in the .cub file
*/
enum e_identifier
{
	NO,
	SO,
	WE,
	EA,
	F,
	C,
	TOTAL
};

/*
** Represent the state of the program
*/
enum e_state
{
	PARSING,
	INIT,
	GAME,
	STOP
};

/*
** Just a simple struct draw the minimap
*/
typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;

typedef struct s_vector_d
{
	double	x;
	double	y;
}	t_vector_d;

typedef struct s_vector_i
{
	int	x;
	int	y;
}	t_vector_i;

typedef struct s_player
{
	t_vector_d	pos;
	t_vector_d	dir;
	t_vector_d	plane;
	double	move_speed;
	double	rot_speed;
}	t_player;

typedef struct s_ray
{
	t_vector_d	ray_dir;
	t_vector_d	side_dist;
	t_vector_d	delta_dist;
	t_vector_i	map;
	t_vector_i	step;
	double		camera_x;
	double		perp_wall_dist;
	int			hit;
	int			side;
	int 		x;
	int			line_height;
	int			draw_start;
	int			draw_end;
}	t_ray;

/*
** Simple struct used to make and array of tuple, used to parse each line of the
** .cub file
*/
typedef struct s_tuple
{
	char				*id_str;
	enum e_identifier	enum_v;
	int					i;
}	t_tuple;

/*
** Also used to parse the .cub file and store the informations
**		id: identifier of the element
**		union {
**			info_texture: texture path of the identifier;
**			info_rgb: RGB value of the identifier;
**		}
*/
typedef struct s_elements
{
	char	*id;
	union {
		char	*info_tex;
		int		*info_rgb;
	};
}	t_elements;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		width;
	int		height;
	int		bpp; // bits per pixel, when divided by 8 gives the number of bytes per pixel
	int		line_length;
	int		endian;
}	t_img;

/*
**	Main struct contain different elements used for parsing and game 
**	management.
**		id_tab: array of t_elements used to store the informations
**		state: represent the state of the program
**		present :
**		=> identifier present in the .cub file that i alread parsed
**		=> bitwise operation to check if the identifier is present 1 or not 0
**		all_id_present: represent the value if all identifier are present
*/
typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			img;
	t_img			tex_img[4];
	t_elements		*id_tab;
	size_t			state;
	size_t			present_id;
	size_t			all_id_present;
	unsigned int	flag_error;
	char			keys[512];
	char			*line_gnl;
	char			**map;
	t_list			*map_list;
	size_t			longest_line;
	int				flag_map_start;
	int				map_width;
	int				map_height;
	int				player_pos_x;
	int				player_pos_y;
	int				player_dir;
	double			window_width;
	double			window_height;
	t_player		player;
	t_ray			ray;
}	t_data;

		/* Parser file name */
int		check_file_name(char *file_name);

		/* Parser file content */
void	parser(t_data *data, char *file_name);
int		parse_identifier(t_data *data, int fd);
void	check_line(t_data *data, char *trimed);
void	check_double(t_data *data, size_t id, char *line);
int		*parse_rgb(t_data *data, char *line);
char	*parse_tex(t_data *data, char *line);
void	error_empty_line(t_data *data, char *line);

		/* Parse map */
void	parse_raw_map(t_data *data, int fd);
void	check_map(t_data *data);
void	fill_map(t_data *data);

		/* Utils */
int		ft_exit_program(t_data *data, char *s);
int		ft_split_len(char **split);
void	ft_free_split(char **split);
void	ft_replace_char(char *str, char find, char replace);

		/* Games */
void	run_game(t_data *data);

		/* Key management */
int		key_press(int keycode, t_data *data);
int		key_release(int keycode, t_data *data);
int		close_window(t_data *data);
void	ft_destroy_mlx(t_data *data);

		/* Draw */
int		encode_rgb(uint8_t red, uint8_t green, uint8_t blue);
void	my_pixel_put(t_img *img, int x, int y, int color);
int		render_rectanlge(t_img *img, t_rect rect);
int		render(t_data *data);
void	raycast(t_data *data);
void	draw_wall(t_data *data);
void	key_manager(t_data *data);

		/* Vector */
void	set_vector_d(t_vector_d *vector, double x, double y);
void	set_vector_i(t_vector_i *vector, int x, int y);
void	rotate_vector(t_vector_d *vector, double rotspeed);


#endif //CUB3D_H