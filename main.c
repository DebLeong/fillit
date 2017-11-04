/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 19:24:18 by dleong            #+#    #+#             */
/*   Updated: 2017/11/03 21:40:34 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit input_file\n");
		return (-1);
	}
	if ((fd == -1) || (!read_file(argv[1])))
	{
		ft_putstr("error\n");
		return (0);
	}
	solve(fd);
	return (0);
}

void	solve(int fd)
{
	char	**all_buff;
	char	*board;
	int		b_len;
	t_list	*curr_lst;

	all_buff = ft_memalloc(sizeof(char) * 22 * (26 + 1));
	all_buff = ft_maketet(fd);
	b_len = ft_findbigsquare(ft_count_tetro(all_buff));
	board = ft_strnew(sizeof(char) * 121);
	ft_bzboard(board, (size_t)b_len);
	curr_lst = tetlst(all_buff);
	while (!(recursive_solver(curr_lst, board, b_len, 0)))
	{
		b_len++;
		board = ft_bzboard((char*)board, (size_t)b_len);
	}
	ft_putstr(board);
}
