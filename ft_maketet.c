/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maketet.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmacrae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 18:28:07 by cmacrae           #+#    #+#             */
/*   Updated: 2017/10/23 22:03:50 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fil_libft.h"

char **ft_maketet(int fd)
{
	char *buf;
	char **all_buf;
	int i;

	i = 0;
	all_buf = (char**)ft_memalloc(sizeof(char*) * 26);
	buf = ft_strnew(20);
	while (read(fd, buf, 21) && i < 4)
	{
		buf[21] = '\0';
		all_buf[i] = ft_strdup(buf);
		buf = ft_strnew(20);
		i++;
	}
	all_buf[i] = NULL;
	return (all_buf);
}

/*
int main(void)
{
	int		fd;
	int		i;
	char	**all_buff;

	i = 0;
	fd = open("valid", O_RDONLY);
	all_buff = ft_maketet(fd);
	while (all_buff[0][i] != '\0')
	{
		ft_putstr(all_buff[i]);
		i++;
	}

	return (0);
}
*/
