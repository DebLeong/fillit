/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makelist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmacrae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 18:28:07 by cmacrae           #+#    #+#             */
/*   Updated: 2017/09/29 02:25:53 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fil_libft.h"

//function counts len of tetromino from all_buff array
int	count_len (char **all_buff)
{
	int i;
	int j;

	i = 0;
	j = 24;
	while (all_buff[i] == '0')
		i++;
	while (all_buff[j] == '0')
		j--;
	return ((j / 5) - (i / 5));
}

//function counts width of tetromino from all_buff array
int	count_width (char **all_buff)
{
	int i;
	int j;
	int leftmost;
	int	rightmost;

	i = 0;
	j = 0;
	leftmost = 0;
	rightmost = 4;
	while (j < 5)
	{
		while (all_buff[i] && all_buff[i] != '\n')
		{
			while (all_buff[i] == '\0')
				i++;
			if (i > leftmost)
				leftmost = i;
		}
		j++;
	}
	i = 24;
	j = 0;
	while (j < 5)
	{
		while (all_buff[i] && all_buff[i] == '\0')
		{
			while (all_buff[i] == '\0')
				i--;
			if ((i % 5) < rightmost)
				rightmost = i;
		}
		j--;
	}
	return (j - i + 1);
}

//function creates list which store each tetromino string
//with its length and width
t_list	*tetlst(char **all_buff)
{
	int		i;
	t_list	*list;

	i = 0;
	while (all_buff)
	{
		list->maketet = all_buff[i];
		list->length = count_len(all_buff[i]);
		list->width = count_width(all_buff[i]);
		list = list->next;
        i++;
	}
    list->next = NULL;
}
