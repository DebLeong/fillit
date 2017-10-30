/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maketet.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmacrae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 18:28:07 by cmacrae           #+#    #+#             */
/*   Updated: 2017/10/29 18:06:22 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fil_libft.h"

char	**ft_maketet(int fd)
{
	char	*buf;
	char	**all_buf;
	int		i;

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

int		ft_count_tetro(char **all_buff)
{
	int	count;

	count = 0;
	while (all_buff[count])
		count++;
	return (count);
}

int		ft_findbigsquare(int tet_quan)
{
	int	b_len;

	b_len = 4;
	while ((b_len << 2) < (tet_quan * 4))
		b_len++;
	return (b_len);
}
