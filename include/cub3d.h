/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:43:51 by mzaraa            #+#    #+#             */
/*   Updated: 2023/01/18 18:51:42 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "colors.h"

# define WHITESPACE " \t\n\v\f\r"
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
	INIT,
	PARSE_ID,
	PARSE_MAP,
	GAME,
	STOP
};

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
	t_elements		*id_tab;
	size_t			state;
	size_t			present_id;
	size_t			all_id_present;
	unsigned int	flag_error;
	char			*line_gnl;
	char			**map;
	t_list			*map_list;
	int				map_width;
	int				map_height;
	int				player_pos_x;
	int				player_pos_y;
	int				player_dir;
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
int		dodge_empty_line(char *line);

		/* Parse map */
void	parse_map(t_data *data, int fd);
void	check_is_good_map(t_data *data);
void	fill_map(t_data *data);

		/* Utils */
void	ft_exit_program(t_data *data);
int		ft_split_len(char **split);
void	ft_free_split(char **split);

#endif //CUB3D_H