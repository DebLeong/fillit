/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 15:39:59 by dleong            #+#    #+#             */
/*   Updated: 2017/11/02 15:25:33 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			test_pos(t_list *tetlst, char *board, int b_len, int b_pos)
{
	int		t_pos;
	int		h;
	int		v;
	char	*tetro;
	int		x = b_pos % (b_len + 1);
	int		y = b_pos / (b_len + 1);
	int		placed_count;

	t_pos = 0;
	h = 0;
	v = 0;
	placed_count = 0;
	tetro = &tetlst->tetro[t_pos];
	while ((v < tetlst->length) && ((y + v) < b_len))
	{
		if (board[b_pos] == '\0')
			return (0);
		h = 0;
		t_pos = 0 + (v * tetlst->total_width);
		printf("--------\n");
		printf("b_len is %i\n", b_len);
		v += y;
		printf("v is: %i\n", v);
		b_pos = x + (v * (b_len + 1));
		while ((h < tetlst->width) && ((x + h) < b_len))
		{
			printf("offset_w is %i\n", x);
			printf("tetro is %i\n", t_pos);
			printf("board is %i\n", b_pos);
			printf("tetro[t_pos] is %c\n", tetro[t_pos]);
			printf("board[b_pos] is %c\n\n", board[b_pos]);
			if ((tetro[t_pos] == '#') && (board[b_pos] != '.'))
			{
				write (1, "returned\n", 9);
				return (0);
			}
			b_pos++;
			t_pos++;
			h++;
		}
		v++;
	}
	if (t_pos < (tetlst->total_width * (tetlst->length - 1) + tetlst->width - 1))
		return (0);
	return (1);
}

void		place_tet(t_list *tetlst, char *board, int b_len, int b_pos)
{
	int		t_pos;
	int		x;
	int		y;
	char	*tetro;
	int		offset_w = b_pos % (b_len + 1);
	int		offset_l = b_pos / (b_len + 1);

	t_pos = 0;
	x = 0;
	y = 0;
	tetro = &tetlst->tetro[t_pos];
	while ((y < tetlst->length) || ((offset_l + y) < b_len))
	{
		x = 0;
		t_pos = 0 + (y * tetlst->total_width);
		y = y + offset_l;
		b_pos = offset_w + (y * (b_len + 1));
		while ((x < tetlst->width) && ((offset_w + x) < b_len))
		{
			if (tetro[t_pos] == '#')
				board[b_pos] = tetlst->letter;
			b_pos++;
			t_pos++;
			x++;
		}
		y++;
	}
}

void		del_tet(t_list *tetlst, char *board, int b_len, int b_pos)
{
	int		t_pos;
	int		x;
	int		y;
	char	*tetro;
	int		offset_w = b_pos % (b_len + 1);
	int		offset_l = b_pos / (b_len + 1);

	t_pos = 0;
	x = 0;
	y = 0;
	tetro = &tetlst->tetro[t_pos];
	while ((y < tetlst->length) || ((offset_l + y) < b_len))
	{
		x = 0;
		t_pos = 0 + (y * tetlst->total_width);
		y = y + offset_l;
		b_pos = offset_w + (y * (b_len + 1));
		while ((x < tetlst->width) && ((offset_w + x) < b_len))
		{
			if (board[b_pos] == tetlst->letter)
				board[b_pos] = '.';
			b_pos++;
			t_pos++;
			x++;
		}
		y++;
	}
}

int			recursive_solver(t_list *tetlst, char *board, int b_len, int b_pos)
{
	t_list	*root;

	root = tetlst;
	if (root == NULL)
		return (1);
	while (board[b_pos] != '\0')
	{
		if (test_pos(root, board, b_len, b_pos))
		{
			ft_putstr("placed\n");
			place_tet(root, board, b_len, b_pos);
			ft_putstr(board);
			printf("\n");
			if (recursive_solver(root->next, board, b_len, 0))
				return (1);
			del_tet(root, board, b_len, b_pos);
		}
		b_pos++;
	}
	return (0);
}
