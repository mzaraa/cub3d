/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:43:51 by mzaraa            #+#    #+#             */
/*   Updated: 2023/01/11 17:02:52 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

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
** Used to parse the .cub file and store the informations
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

typedef struct s_data
{
	t_elements	*id_tab;
	int			state;
}	t_data;

		/* Libft functions */
int		ft_strcmp(const char *s1, const char *s2);

		/* Parser */
int		check_file_name(char *file_name);
void	parser(t_data *data, char *file_name);

	/* Utils */
void	ft_exit_program(t_data *data);

#endif //CUB3D_H