/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 21:43:08 by dleong            #+#    #+#             */
/*   Updated: 2017/11/03 21:45:23 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** c[0] is x			c[1] is y		c[2] is offset_x	c[3] is offset_y
** c[4] is placed_tet	c[5] is t_pos
*/

int			test_pos(t_list *tetlst, char *board, int b_len, int b_pos)
{
	int		c[6];

	c[0] = -1;
	c[1] = -1;
	c[2] = b_pos % (b_len + 1);
	c[3] = b_pos / (b_len + 1);
	c[4] = 0;
	c[5] = 0;
	while (++c[1] < tetlst->length)
	{
		c[0] = -1;
		c[5] = 0 + (c[1] * tetlst->total_width);
		b_pos = c[2] + ((c[3] + c[1]) * (b_len + 1));
		while ((++c[0] < (tetlst->total_width - 1)))
		{
			if ((tetlst->tetro[c[5]] == '#') && ((c[0] + c[2]) >= b_len ||
						(c[1] + c[3]) >= b_len || ft_isalpha(board[b_pos])))
				return (0);
			if (tetlst->tetro[c[5]] == '#')
				c[4]++;
			b_pos++;
			c[5]++;
		}
	}
	return (c[4]);
}

/*
** c[0] is x	c[1] is y	c[2] is t_pos
*/

int			place_tet(t_list *tetlst, char *board, int b_len, int b_pos)
{
	int		c[3];
	int		offset_x;
	int		offset_y;

	c[0] = 0;
	c[1] = 0;
	c[2] = 0;
	offset_x = b_pos % (b_len + 1);
	offset_y = b_pos / (b_len + 1);
	while (c[1] < tetlst->length)
	{
		c[0] = 0;
		c[2] = 0 + (c[1] * tetlst->total_width);
		b_pos = offset_x + ((offset_y + c[1]) * (b_len + 1));
		while (c[0] < (tetlst->total_width - 1))
		{
			if (tetlst->tetro[c[2]] == '#')
				board[b_pos] = tetlst->letter;
			b_pos++;
			c[2]++;
			c[0]++;
		}
		c[1]++;
	}
	return (1);
}

/*
** c[0] is x	c[1] is y
*/

void		del_tet(t_list *tetlst, char *board, int b_len, int b_pos)
{
	int		t_pos;
	int		c[2];
	int		offset_x;
	int		offset_y;

	t_pos = 0;
	c[0] = 0;
	c[1] = 0;
	offset_x = b_pos % (b_len + 1);
	offset_y = b_pos / (b_len + 1);
	while (c[1] < tetlst->length)
	{
		c[0] = 0;
		t_pos = 0 + (c[1] * tetlst->total_width);
		b_pos = offset_x + ((offset_y + c[1]) * (b_len + 1));
		while (c[0] < (tetlst->total_width - 1))
		{
			if (board[b_pos] == tetlst->letter)
				board[b_pos] = '.';
			b_pos++;
			t_pos++;
			c[0]++;
		}
		c[1]++;
	}
}

int			recursive_solver(t_list *tetlst, char *board, int b_len, int b_pos)
{
	if (tetlst != NULL)
	{
		while (board[b_pos] != '\0')
		{
			if (test_pos(tetlst, board, b_len, b_pos) == 4)
			{
				place_tet(tetlst, board, b_len, b_pos);
				if (recursive_solver(tetlst->next, board, b_len, 0))
					return (1);
				del_tet(tetlst, board, b_len, b_pos);
			}
			b_pos++;
		}
		return (0);
	}
	return (1);
}
