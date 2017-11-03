/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 15:39:59 by dleong            #+#    #+#             */
/*   Updated: 2017/11/03 00:30:05 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			test_pos(t_list *tetlst, char *board, int b_len, int b_pos)
{
	int		t_pos = 0;
	int		x = 0;
	int		y = 0;
	char	*tetro;
	int		offset_x = b_pos % (b_len + 1);
	int		offset_y = b_pos / (b_len + 1);

	tetro = &tetlst->tetro[t_pos];
	while (y < tetlst->length)
	{
		x = 0;
		t_pos = 0 + (y * tetlst->total_width);
		b_pos = offset_x + (y * (b_len + 1));
		while (x < tetlst->total_width)
		{
			if ((tetro[t_pos] == '#') && (((x + offset_x) >= b_len) || ((y + offset_y) >= b_len)))
				return (0);
			if ((tetro[t_pos] == '#') && (board[b_pos] != '.'))
				return (0);
			x++;
			b_pos++;
			t_pos++;
		}
		y++;
	}
	return (1);
}

int		place_tet(t_list *tetlst, char *board, int b_len, int b_pos)
{
	int		x = 0;
	int		y = 0;
	int		t_pos = 0;
	char	*tetro;
	int		offset_x = b_pos % (b_len + 1);

	tetro = &tetlst->tetro[t_pos];
	while (y < tetlst->length)
	{
		x = 0;
		t_pos = 0 + (y * tetlst->total_width);
		b_pos = offset_x + (y * (b_len + 1));
		while (x < tetlst->total_width)
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

void		del_tet(t_list *tetlst, char *board, int b_len, int b_pos)
{
	int		t_pos = 0;
	int		x = 0;
	int		y = 0;
	char	*tetro;
	int		offset_x = b_pos % (b_len + 1);

	tetro = &tetlst->tetro[t_pos];
	while (y < tetlst->length)
	{
		x = 0;
		t_pos = 0 + (y * tetlst->total_width);
		b_pos = offset_x + (y * (b_len + 1));
		while (x < tetlst->width)
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
	if (tetlst != NULL)
	{
		while (board[b_pos] != '\0')
		{
			if (test_pos(tetlst, board, b_len, b_pos))
			{
				place_tet(tetlst, board, b_len, b_pos);
				if (recursive_solver(tetlst->next, board, b_len, b_pos))
					return (1);
				del_tet(tetlst, board, b_len, b_pos);
			}
			b_pos++;
		}
		return (0);
	}
	return (1);
}
