/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmacrae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 20:50:47 by cmacrae           #+#    #+#             */
/*   Updated: 2017/11/03 21:35:43 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** count[0] is hash
** count[1] is connection
*/

int			ft_checkconnection(char *tetro, int size)
{
	int		i;
	int		count[2];

	i = 0;
	count[0] = 0;
	count[1] = 0;
	while (i < size)
	{
		if (tetro[i] == '#')
		{
			if (tetro[i - 1] == '#' && i >= 1)
				count[1]++;
			if (tetro[i + 1] == '#' && i < size)
				count[1]++;
			if (tetro[i - 5] == '#' && i >= 5)
				count[1]++;
			if (tetro[i + 5] == '#' && i <= 16)
				count[1]++;
			count[0]++;
		}
		i++;
	}
	if ((count[1] == 6 || count[1] == 8) && (count[0] == 4))
		return (1);
	return (0);
}

int			check_tetro_char(char *string, int size)
{
	int		count;
	int		hash;
	int		newline;
	int		dot;
	int		i;

	hash = 0;
	newline = 0;
	dot = 0;
	i = 0;
	count = 0;
	while (i < size)
	{
		if (string[i] == '#')
			hash++;
		if (string[i] == '\n')
			newline++;
		if (string[i] == '.')
			dot++;
		i++;
	}
	if ((hash % 4 != 0) || (dot % 12 != 0))
		return (1);
	return (newline % 5);
}

/*
** c[0] is count
** c[1] is i
*/

int			read_file(char *argv)
{
	int		fd;
	int		c[2];
	char	buff[21];
	char	buff2[20];
	char	file_buff[546];

	c[1] = 0;
	fd = open(argv, O_RDONLY);
	c[0] = read(fd, file_buff, 546);
	if ((c[0] % 21) != 20)
		return (0);
	file_buff[c[0]] = '\0';
	while (c[1] <= (c[0] - 41))
	{
		if (ft_checkconnection(ft_strncpy(buff, &file_buff[c[1]], 21), 21) == 0)
			return (0);
		if (check_tetro_char(ft_strncpy(buff, &file_buff[c[1]], 21), 21) != 0)
			return (0);
		c[1] += 21;
	}
	if ((ft_checkconnection(ft_strncpy(buff2, &file_buff[c[1]], 20), 20) != 1)
		|| (check_tetro_char(ft_strncpy(buff, &file_buff[c[1]], 20), 20) != 4)
		|| (check_tetro_char(ft_strncpy(buff, &file_buff[c[1]], 20), 20) == 1))
		return (0);
	return (1);
}
