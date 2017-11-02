/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 19:24:18 by dleong            #+#    #+#             */
/*   Updated: 2017/11/02 15:03:07 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	//int		res;
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
	/*
	res = ft_onepiece(fd);
	if (res == -1)
	{
		ft_putstr("error\n");
		close(fd);
		return (0);
	}
	*/
	all_buff = ft_maketet(fd);
	b_len = ft_findbigsquare(ft_count_tetro(all_buff));
	board = ft_strnew(sizeof(char) * 121);
	ft_bzboard(board, (size_t)b_len);
	printf("this is the starting board: \n");
	ft_putstr(board);
	curr_lst = tetlst(all_buff);

	t_list	*test;
	test = curr_lst;
	while (test != NULL)
	{
		ft_putstr("tetro:\n");
		ft_putstr(test->tetro);
		printf("length: %i\n", test->length);
		printf("width: %i\n", test->width);
		printf("total width: %i\n", test->total_width);
		printf("tetro letter: %c\n", test->letter);
		write(1, "\n", 1);
		test = test->next;
	}

	while (!(recursive_solver(curr_lst, board, b_len, 0)))
	{
		b_len++;
		printf("b_len incremented by 1 and is now %i\n", b_len);
		printf("------------------------------------\n");
		board = ft_bzboard((char *)board, (size_t)b_len);
		printf("this is what current board looks like: \n");
		ft_putstr(board);
	}

	printf("this is final output: \n");
	ft_putstr(board);
	return (0);
}
