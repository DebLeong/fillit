/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 19:24:18 by dleong            #+#    #+#             */
/*   Updated: 2017/10/30 14:54:32 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	**all_buff;
	char	*board;
	int		b_len;
	t_list	*curr_lst;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit input_file\n");
		return (-1);
	}
	all_buff = ft_memalloc(sizeof(char) * 22 * (26 + 1));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_putstr("error\n");
	all_buff = ft_maketet(fd);
	b_len = ft_findbigsquare(ft_count_tetro(all_buff));
	board = ft_strnew(sizeof(char) * 121);
	ft_bzboard(board, (size_t)b_len);
	curr_lst = tetlst(all_buff);

	/*
	t_list	*test;
	test = curr_lst;
	while (test != NULL)
	{
		ft_putstr("tetro:\n");
		ft_putstr(test->tetro);
		printf("length: %i\n", test->length);
		printf("width: %i\n", test->width);
		write(1, "\n", 1);
		test = test->next;
	}
	*/

	while (!(recursive_solver(curr_lst, board, b_len, 0)))
		ft_bzboard((char *)board, (size_t)b_len++);
	ft_putstr(board);
	return (0);
}
