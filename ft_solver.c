/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dleong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 15:39:59 by dleong            #+#    #+#             */
/*   Updated: 2017/10/23 23:44:50 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fil_libft.h"

//recursive backtracking that takes number of tetros, boardsize and each
//tetro's array (size of 15)
//function that checks whether current position is valid for current tetro shape

int		test_pos(t_list	*tetlst, int board_len)
{
	//char	*board_array[26 * 4 * 4 + 1];
	int		curr_size = board_len * board_len;
	int		curr_pos;
	t_list	*curr_lst;
	int		i;

	i = 0;
	curr_pos = 0;
	curr_lst = tetlst;
	while (curr_lst != NULL && curr_pos < curr_size)
	{
		if (ft_isalpha(curr_pos))
			return (0);
		while (curr_lst->length && i < (curr_lst->width  * curr_lst->length))
		{
			while (curr_lst->width && i < (curr_lst->width * curr_lst->length))
			{
				if (curr_lst->tetro[i] == '#')
					curr_pos++;
				if (ft_isalpha(curr_pos))
					return (0);
				i++;
			}
			curr_pos += 4;
			curr_lst = curr_lst->next;
		}
	}
	return (1);
}

/*
void	fillit_solver(char *tetlst, int board_min_len, 
		int board_max_len)
{
	//This assigns a board with max size of 26 tetro * size of tetro (4x4)
	char*	board_array[26 * 4 * 4 + 1];
	//total board positions currently working with
	int		curr_size = board_min_len * board_min_len;
	//counters for iterating over arrays
	int		row_count  = 0;
	int		board_pos  = 0;
	int     tetro_pos  = 0;
	
	int		fd;
	char	**all_buff;
	t_list	*current;

	all_buff = malloc(sizeof(char) * 52);
	fd = open("valid", O_RDONLY);
	all_buff = ft_maketet(fd);
	current = tetlst(all_buff);

	testwhile ((row_count < board_min_len - 1) && (board_min_len < board_max_len))
	{
		board_array = ft_bzero(board_array, curr_size);
		while ((board_pos % board_min_len) < baord_min_len)
		{
			while (tetlst->next)
			{
				//check whether current position is available
				while (board_array[board_pos] != "." || board_array[board_pos] == '\n')
					board_pos++;
				while (tetlst->maketet[tetro_pos] != '\0')
				{
					while (tetlst->maketet[tetro_pos] != '\n')
						board_array[board_pos++] = tetro_array[tetro_pos++];
					board_pos += 5;
				}
				tetlst = tetlst->next;
				board_pos = 0;
			}
		}
		free(curr_pos);
	}
}
*/

int main(void)
{
	int		fd;
	char	**all_buff;
	int		result;
	t_list	*current;

	result = 0;
	all_buff = malloc(sizeof(char) * 52);
	fd = open("valid", O_RDONLY);
	all_buff = ft_maketet(fd);
	current = tetlst(all_buff);
	result = test_pos((t_list *)tetlst, 4);
	printf("%i\n", result);
}
