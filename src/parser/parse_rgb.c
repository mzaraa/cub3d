/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:11:39 by mzaraa            #+#    #+#             */
/*   Updated: 2023/02/21 17:58:36 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	only_digits(char *rgb)
{
	int	i;

	i = 0;
	while (rgb[i])
	{
		if (ft_isdigit(rgb[i]) == 0)
			return (1);
		i++;
	}
	if (i > 3)
		return (1);
	if (ft_atoi(rgb) > 255)
		return (1);
	return (0);
}

int	check_rgb_value(char *rgb)
{
	char	**rgb_split;

	rgb_split = ft_split(rgb, ",");
	if (rgb_split == NULL || ft_split_len(rgb_split) != 3
		|| only_digits(rgb_split[0]) || only_digits(rgb_split[1])
		|| only_digits(rgb_split[2]))
	{
		ft_free_split(rgb_split);
		return (1);
	}
	ft_free_split(rgb_split);
	return (0);
}

int	check_comma(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == ',')
			count++;
		i++;
	}
	if (count > 2)
		return (1);
	return (0);
}

/*
**	Parse the rgb values from the line+1 (to skip the identifier) and split it
**	into an array of strings. Check if the array size is 3 or more and if the 
**	values are digits. If not, free the array and the line and exit the program.
*/
int	*parse_rgb(t_data *data, char *line, char **split)
{
	char	**rgb;
	char	**rgb_int;
	int		*ret;

	rgb = ft_split(line, " \n\t");
	if (rgb == NULL || ft_split_len(rgb) != 2)
		data->flag_error = 1;
	if (data->flag_error || check_rgb_value(rgb[1]) || check_comma(rgb[1]))
	{
		ft_free_split(rgb);
		ft_free_split(split);
		free(line);
		ft_exit_program(data, "Error\nInvalid rgb value => Standart: ID R,G,B");
	}
	rgb_int = ft_split(rgb[1], ",");
	ret = malloc(sizeof(int) * 3);
	ret[0] = ft_atoi(rgb_int[0]);
	ret[1] = ft_atoi(rgb_int[1]);
	ret[2] = ft_atoi(rgb_int[2]);
	ft_free_split(rgb_int);
	ft_free_split(rgb);
	return (ret);
}
