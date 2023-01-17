/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 09:46:31 by mzaraa            #+#    #+#             */
/*   Updated: 2023/01/17 18:04:03 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0 || (!str1 && !str2))
		return (0);
	while (str1[i] && str1[i] == str2[i] && i < n - 1)
		i++;
	return (str1[i] - str2[i]);
}

// static void		printf(int n)
// {
// 	if (n > 0)
// 		write(1, "1", 1);
// 	else if (n < 0)
// 		write(1, "-1", 2);
// 	else
// 		write(1, "0", 1);
// }

// int				main(int argc, const char *argv[])
// {
// 	int		arg;

// 	alarm(5);
// 	if (argc == 1)
// 		return (0);
// 	else if ((arg = atoi(argv[1])) == 1)
// 		printf(ft_strncmp("salut", "salut", 5));
// 	else if (arg == 2)
// 		printf(ft_strncmp("test", "testss", 7));
// 	else if (arg == 3)
// 		printf(ft_strncmp("testss", "test", 7));
// 	else if (arg == 4)
// 		printf(ft_strncmp("test", "tEst", 4));
// 	else if (arg == 5)
// 		printf(ft_strncmp("", "test", 4));
// 	else if (arg == 6)
// 		printf(ft_strncmp("test", "", 4));
// 	else if (arg == 7)
// 		printf(ft_strncmp("abcdefghij", "abcdefgxyz", 3));
// 	else if (arg == 8)
// 		printf(ft_strncmp("abcdefgh", "abcdwxyz", 4));
// 	else if (arg == 9)
// 		printf(ft_strncmp("zyxbcdefgh", "abcdwxyz", 0));
// 	else if (arg == 10)
// 		printf(ft_strncmp("abcdefgh", "", 0));
// 	else if (arg == 11)
// 		printf(ft_strncmp("test\200", "test\0", 6));
// 	return (0);
// }
