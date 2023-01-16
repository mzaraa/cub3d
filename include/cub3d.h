/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:43:51 by mzaraa            #+#    #+#             */
/*   Updated: 2023/01/16 17:15:03 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "colors.h"
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
		char	*info_texture;
		char	**info_rgb;
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
}	t_data;

		/* Parser file name */
int		check_file_name(char *file_name);

		/* Parser file content */
void	parser(t_data *data, char *file_name);
void	parse_identifier(t_data *data, int fd);
int		check_line(t_data *data, char *line);
void	check_double(t_data *data, size_t id, char *line);
char	**parse_rgb(t_data *data, char *line);
char	*parse_texture(t_data *data, char *line);

		/* Utils */
void	ft_exit_program(t_data *data);
int		ft_split_len(char **split);

#endif //CUB3D_H