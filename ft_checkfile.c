/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmacrae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 20:50:47 by cmacrae           #+#    #+#             */
/*   Updated: 2017/11/03 21:26:29 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_checkconnection(char *tetro, int size)
{
	int		i;
	int		connection;
	int		hash;

	hash = 0;
	i = 0;
	connection = 0;
	while (i < size)
	{
		if (tetro[i] == '#')
		{
			if (tetro[i - 1] == '#' && i >= 1)
				connection++;
			if (tetro[i + 1] == '#' && i < size)
				connection++;
			if (tetro[i - 5] == '#' && i >= 5)
				connection++;
			if (tetro[i + 5] == '#' && i <= 16)
				connection++;
			hash++;
		}
		i++;
	}
	if ((connection == 6 || connection == 8) && (hash == 4))
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

int			read_file(char *argv)
{
	int		fd;
	int		i;
	char	buff[21];
	char	buff2[20];
	char	file_buff[546];
	int		count;

	i = 0;
	fd = open(argv, O_RDONLY);
	count = read(fd, file_buff, 546);
	if ((count % 21) != 20)
		return (0);
	file_buff[count] = '\0';
	while (i <= (count - 41))
	{
		if (ft_checkconnection(ft_strncpy(buff, &file_buff[i], 21), 21) == 0)
			return (0);
		if (check_tetro_char(ft_strncpy(buff, &file_buff[i], 21), 21) != 0)
			return (0);
		i += 21;
	}
	if ((ft_checkconnection(ft_strncpy(buff2, &file_buff[i], 20), 20) != 1)
		|| (check_tetro_char(ft_strncpy(buff, &file_buff[i], 20), 20) != 4)
		|| (check_tetro_char(ft_strncpy(buff, &file_buff[i], 20), 20) == 1))
		return (0);
	return (1);
}
