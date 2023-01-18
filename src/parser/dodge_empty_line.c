/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dodge_empty_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:36:19 by mzaraa            #+#    #+#             */
/*   Updated: 2023/01/18 18:46:17 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	dodge_empty_line(char *line)
{
	char	*trimed;

	trimed = ft_strtrim(line, WHITESPACE);
	if ((ft_isspace(line[0]) && !*trimed))
		return (1);
	return (0);
}
