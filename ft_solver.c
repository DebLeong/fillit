/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 15:39:59 by dleong            #+#    #+#             */
/*   Updated: 2017/10/29 18:14:08 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fil_libft.h"

int		test_pos(t_list *tetlst, char *board, int b_len, int b_pos)
{
	int		t_pos;
	int		count[2];
	char	*tetro;

	t_pos = 0;
	count[0] = -1;
	count[1] = -1;
	tetro = &tetlst->tetro[t_pos];
	while (++count[1] < tetlst->length)
	{
		count[0] = -1;
		t_pos = 0 + (count[1] * tetlst->width);
		while ((++count[0] < tetlst->width) && ((b_pos % (b_len + 1)) < b_len))
		{
			if ((tetro[t_pos] == '#') && (board[b_pos] != '.'))
				return (0);
			b_pos++;
			t_pos++;
		}
		if (t_pos < (tetlst->width - 1))
			return (0);
		b_pos = b_pos + (b_len - tetlst->width + 1);
	}
	return (1);
}

int		place_tet(t_list *tetlst, char *board, int b_len, int b_pos)
{
	int		t_pos;
	int		x;
	int		y;
	char	*tetro;

	t_pos = 0;
	x = 0;
	y = 0;
	tetro = &tetlst->tetro[t_pos];
	while (y < tetlst->length)
	{
		x = 0;
		t_pos = 0 + (y * tetlst->width);
		while ((x < tetlst->width) && ((b_pos % (b_len + 1)) < b_len))
		{
			if (tetro[t_pos] == '#')
				board[b_pos] = tetlst->letter;
			b_pos++;
			t_pos++;
			x++;
		}
		y++;
		b_pos = b_pos + (b_len - tetlst->width + 1);
	}
	return (1);
}

void	del_tet(t_list *tetlst, char *board, int b_len, int b_pos)
{
	int		t_pos;
	int		count[2];
	char	*tetro;

	count[1] = 0;
	t_pos = 0;
	tetro = &tetlst->tetro[t_pos];
	while (count[1] < tetlst->length)
	{
		count[0] = 0;
		t_pos = count[1] * tetlst->width;
		while (count[0] < tetlst->width)
		{
			if (board[b_pos] == tetlst->letter)
				board[b_pos] = '.';
			b_pos++;
			t_pos++;
			count[0] += 1;
		}
		count[1] += 1;
		b_pos = b_pos + (b_len - tetlst->width + 1);
	}
}

int		recursive_solver(t_list *tetlst, char *board, int b_len, int b_pos)
{
	t_list	*root;

	root = tetlst;
	if (root == NULL)
		return (1);
	while (b_pos < (int)ft_strlen(board))
	{
		if (test_pos(root, board, b_len, b_pos))
		{
			place_tet(root, board, b_len, b_pos);
			if (recursive_solver(root->next, board, b_len, b_pos + 1))
				return (1);
			del_tet(root, board, b_len, b_pos);
		}
		b_pos++;
	}
	if (b_pos == ((int)ft_strlen(board) - 1))
		return (1);
	return (0);
}

int		main(void)
{
	int		fd;
	char	**all_buff;
	char	*board;
	int		b_len;
	t_list	*curr_lst;

	all_buff = ft_memalloc(sizeof(char) * 22 * (26 + 1));
	fd = open("valid1", O_RDONLY);
	all_buff = ft_maketet(fd);
	b_len = ft_findbigsquare(ft_count_tetro(all_buff));
	board = ft_strnew(sizeof(char) * 121);
	ft_bzboard(board, (size_t)b_len);
	curr_lst = tetlst(all_buff);
	while (!(recursive_solver(curr_lst, board, b_len, 0)))
	{
		b_len++;
		ft_bzboard((char *)board, (size_t)b_len);
	}
	ft_putstr(board);
	return (0);
}
