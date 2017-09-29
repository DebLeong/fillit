/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 15:39:59 by dleong            #+#    #+#             */
/*   Updated: 2017/09/28 13:07:03 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

//recursive backtracking that takes number of tetros, boardsize and each
//tetro's array (size of 15)
//
//structure of char *tetro_array:
//[0,0,0,0,\n,0,0,0,0,\n,0,0,0,0,\n,0,0,0,0]

//function that checks whether current position is valid for current tetro shape
//

void	fillit_solver(char **tetro_array, int board_min_len, 
	   int board_max_len)
{
	//This assigns a board with max size of 26 tetro * size of tetro (4x4)
	char*	board_array[26 * 4 * 4 + 1];
	int		curr_size = board_min_len * board_min_len;
	int		curr_row = pos / size;
	int		curr_col = pos % size;
	int		i = 0;
	int		j  = 0;

	while (i < curr_size)
	{
		board_array = ft_bzero(board_array, curr_size);
		while (*tetro_array)
		{
			//check whether current position is available starting from
			//the beginning for each tetro
			if (board_array[j] == 0)
				j++;
			while (*tetro_array[i] != '\n')
				i++;
				board_array[j] = *tetro_array[i];
			i++;
		curr_pos++;
	}
	free(curr_pos);
}
