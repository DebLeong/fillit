/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makelist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmacrae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 18:28:07 by cmacrae           #+#    #+#             */
/*   Updated: 2017/11/03 01:33:45 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** function returns vertical coordinates of tetromino from 1D array
*/

int		*v_pos(char *tetro)
{
	int i;
	int j;
	int	*result;

	i = 0;
	j = 19;
	result = NULL;
	result = ft_memalloc(sizeof(int) * 2);
	while (tetro[i] == '.' || tetro[i] == '\n')
		i++;
	while (tetro[j] == '.' || tetro[j] == '\n')
		j--;
	result[0] = i / 5;
	result[1] = j / 5;
	return (result);
}

/*
** function returns left horizontal coordinate of tetromino from 1D array
*/

int		h_pos_l(char *tetro)
{
	int i;
	int j;
	int leftmost;

	j = 0;
	leftmost = 3;
	while (j < 4)
	{
		i = 5 * j;
		while ((tetro[i] == '.' || tetro[i] == '\n') &&
				(i < ((j + 1) * 5 - 1)))
			i++;
		if ((i % 5) < leftmost)
			leftmost = i % 5;
		j++;
	}
	return (leftmost);
}

/*
** function returns right horizontal coordinate of tetromino from 1D array
*/

int		h_pos_r(char *tetro)
{
	int i;
	int j;
	int	rightmost;

	j = 4;
	rightmost = 0;
	while (j > 0)
	{
		i = 4 * j;
		while (tetro[i] == '.' || tetro[i] == '\n')
			i--;
		if ((i % 5) > rightmost)
			rightmost = i % 5;
		j--;
	}
	return (rightmost);
}

/*
** function moves tetro to upperleftmost corner and return
** array of 2D array of tetros of 4 * 5
*/

char	*move_upperleft(char *all_buff)
{
	int		count[3];
	int		offset;
	int		l;
	int		w;
	char	*result;

	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	result = ft_memalloc(sizeof(char) * 21);
	l = (v_pos(all_buff)[1] - v_pos(all_buff)[0] + 1);
	w = (h_pos_r(all_buff) - h_pos_l(all_buff) + 1);
	offset = h_pos_l(all_buff);
	while (count[2] < 20)
	{
		while ((count[2] % 5) < offset)
			count[2]++;
		result[count[1]] = all_buff[count[2]];
		count[2]++;
		count[1]++;
	}
	w = 5 - offset;
	result = ft_strsub(result, v_pos(all_buff)[0] * w, l * w);
	result[l * w] = '\0';
	return (result);
}

/*
** function creates list which store each tetromino string
** with its length and width
*/

t_list	*tetlst(char **all_buff)
{
	int			i;
	t_list		*newlst;
	t_list		*root;
	t_list		*tmp;

	i = -1;
	root = (struct s_list *)ft_memalloc(sizeof(t_list));
	newlst = root;
	while (all_buff[++i])
	{
		newlst->length = (v_pos(all_buff[i])[1] - v_pos(all_buff[i])[0] + 1);
		newlst->width = (h_pos_r(all_buff[i]) - h_pos_l(all_buff[i]) + 1);
		newlst->total_width = 5 - h_pos_l(all_buff[i]);
		newlst->tetro = move_upperleft(all_buff[i]);
		newlst->letter = 65 + i;
		if (all_buff[i + 1])
		{
			tmp = (struct s_list *)ft_memalloc(sizeof(t_list));
			newlst->next = tmp;
			newlst = newlst->next;
		}
	}
	newlst->next = NULL;
	return (root);
}
