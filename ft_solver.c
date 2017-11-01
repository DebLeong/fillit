/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 15:39:59 by dleong            #+#    #+#             */
/*   Updated: 2017/10/30 14:50:09 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		test_pos(t_list *tetlst, char *board, int b_len, int b_pos)
{
	int		t_pos;
	int		x;
	int		y;
	char	*tetro;
	int		offset_w = b_pos % (b_len + 1);
	int		offset_l = b_pos / b_len;

	t_pos = 0;
	x = 0;
	y = 0;
	tetro = &tetlst->tetro[t_pos];
	while ((y < tetlst->length) && ((offset_l + y) < b_len))
	{
		x = 0;
		t_pos = 0 + (y * tetlst->width);
		b_pos = offset_w + (y * (b_len + 1));
		while ((x < tetlst->width) && ((offset_w + x) < b_len))
		{
			if ((tetro[t_pos] == '#') && (board[b_pos] != '.'))
				return (0);
			b_pos++;
			t_pos++;
			x++;
		}
		y++;
	}
	return (1);
}

int		place_tet(t_list *tetlst, char *board, int b_len, int b_pos)
{
	int		t_pos;
	int		x;
	int		y;
	char	*tetro;
	int		offset_w = b_pos % (b_len + 1);
	int		offset_l = b_pos / b_len;

	t_pos = 0;
	x = 0;
	y = 0;
	tetro = &tetlst->tetro[t_pos];
	while ((y < tetlst->length) && ((offset_l + y) < b_len))
	{
		x = 0;
		t_pos = 0 + (y * tetlst->width);
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
	return (1);
}

void	del_tet(t_list *tetlst, char *board, int b_len, int b_pos)
{
	int		t_pos;
	int		x;
	int		y;
	char	*tetro;
	int		offset_w = b_pos % (b_len + 1);
	int		offset_l = b_pos / b_len;

	t_pos = 0;
	x = 0;
	y = 0;
	tetro = &tetlst->tetro[t_pos];
	while ((y < tetlst->length) && ((offset_l + y) < b_len))
	{
		x = 0;
		t_pos = 0 + (y * tetlst->width);
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
			//ft_putstr("placed\n");
			//printf("b_pos is %i\n", b_pos);
			place_tet(root, board, b_len, b_pos);
			//tt_putstr(board);
			if (recursive_solver(root->next, board, b_len, b_pos))
				return (1);
			del_tet(root, board, b_len, b_pos);
		}
		b_pos++;
	}
	return (0);
}
