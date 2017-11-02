/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmacrae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 20:50:47 by cmacrae           #+#    #+#             */
/*   Updated: 2017/11/01 17:28:12 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** testing read function
** fd = filedescriptor
*/

int	ft_aroundcheck(char *buf)
{
	int c;
	int k;

	c = 0;
	k = 0;
	while (buf[c] != '\0')
	{
		if (buf[c] == '#')
		{
			if (buf[c + 1] == '#' && buf[c + 5] == '#')
				k++;
			k++;
		}
		if (buf[c] == '#' && c > 0)
		{
			if (buf[c - 1] == '#' && buf[c + 1] == '#' && buf[c + 5] == '#')
				k++;
			k++;
		}
		c++;
	}
	return (k);
}

int	ft_checkmore(char *buf)
{
	int *loc;
	int i;
	int j;

	i = 0;
	j = 0;
	loc = (int *)ft_memalloc(sizeof(int) * 4);
	while (buf[i] != '\0')
	{
		if (j > 4)
			break ;
		if (buf[i] == '#')
		{
			loc[j] = i;
			j++;
		}
		i++;
	}
	if (j != 4 && buf[i] != '\0')
		return (-1);
	if (*buf && ft_aroundcheck(buf) >= 8)
		return (0);
	return (-1);
}

/*
** this checks if string is the right size/ has the right characters
** fix it
*/

int	ft_checkvalidity(char *buf)
{
	int i;

	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[4] != '\n' || buf[9] != '\n' || buf[14] != '\n'
		|| buf[19] != '\n')
			return (-1);
		if (buf[i] != '#' && buf[i] != '.' && buf[i] != '\n')
			return (-1);
		i++;
	}
	if (ft_checkmore(buf) != 0)
		return (-1);
	return (0);
}

int	ft_onepiece(int fd)
{
	char	*buf;
	int		bytes_read;

	buf = ft_strnew(20);
	if (fd < 0)
		exit(1);
	bytes_read = read(fd, buf, 21);
	if (ft_checkvalidity(buf) != 0)
		return (-1);
	if (bytes_read > 0)
		return (ft_onepiece(fd));
	else
		return (0);
}
