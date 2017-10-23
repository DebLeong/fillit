/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makelist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmacrae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 18:28:07 by cmacrae           #+#    #+#             */
/*   Updated: 2017/10/23 16:28:31 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fil_libft.h"

//function returns vertical coordinates of tetromino from 1D array
int	*vert_pos(char *tetro)
{
	int i;
	int j;
	int	*result = NULL;

	i = 0;
	j = 20;
	result = malloc(sizeof(int) * 2);
	while (tetro[i] == '.' || tetro[i] == '\n')
		i++;
	while (tetro[j] == '.' || tetro[j] == '\n')
		j--;
	result[0] = i / 5;
	result[1] = j / 5;
	return (result);
}

//function returns horizontal coordinates of tetromino from 1D array
int	*hori_pos(char *tetro)
{
	int i;
	int j;
	int leftmost;
	int	rightmost;
	int	*result = NULL;

	j = 0;
	leftmost = 3;
	rightmost = 0;
	result = malloc(sizeof(int) * 2);
	while (j < 4)
	{
		i = 4 * j;
		while (tetro[i] == '.' || tetro[i] == '\n')
			i++;
		if ((i % 5) < leftmost)
			leftmost = i % 5;
		j++;
	}
	while (j > 0)
	{
		i = 4 * j;
		while (tetro[i] == '.' || tetro[i] == '\n')
			i--;
		if ((i % 5) > rightmost)
			rightmost = i % 5;
		j--;
	}
	result[0] = leftmost;
	result[1] = rightmost;
	return (result);
}

//function moves tetro to upperleftmost corner and return
//array of 2D array of tetros of 4 * 5 
char    *move_upperleft(char *all_buff)
{
	int		i;
	int		j;
	int		k;
	int		count;
	int		l;
	int		w;
	char	*result;

	i = 0;
	j = 0;
	k = 0;
	result = malloc(sizeof(char) * 21);
	l = (vert_pos(all_buff)[1] - vert_pos(all_buff)[0] + 1);
	w = (hori_pos(all_buff)[1] - hori_pos(all_buff)[0] + 1);
	count = hori_pos(all_buff)[0] - 0;
	while (k < 20)
	{
		if ((k % 5) < count)
		{
			result[j] = all_buff[k + count];
			k = k + count + 1;
		}
		else
		{
			result[j] = all_buff[k];
			k = k + 1;
		}
		j++;
	}
	/*
	printf("This is before trim:\n");
	ft_putstr(result);
	printf("\n");
	*/
	result = ft_strsub(result, vert_pos(all_buff)[0] * (5 - count), l * w + l);
    return (result);
}

//function creates list which store each tetromino string
//with its length and width
t_list	*tetlst(char **all_buff)
{
	int			i;
	int			l;
	int			w;
	t_list		*newlst;
	t_list		*root;
	t_list		*tmp;

	i = 0;
	root = (struct s_list *)malloc(sizeof(t_list));
	newlst = root;
	while (all_buff[i])
	{
        //assigning upperleft aligned tetromino to list
		l = (vert_pos(all_buff[i])[1] - vert_pos(all_buff[i])[0] + 1);
		w = (hori_pos(all_buff[i])[1] - hori_pos(all_buff[i])[0] + 1);
		newlst->tetro = move_upperleft(all_buff[i]);
		newlst->length = l;
		newlst->width = w;
		if (all_buff[i + 1])
		{
			tmp = (struct s_list *)malloc(sizeof(t_list));
			newlst->next = tmp;
			newlst = newlst->next;
		}
		else
			newlst->next = NULL;
        i++;
	}
    return (root);
}

int main(void)
{
    char	**all_buff;
	int		tetronum;
	t_list	*current;;
	/*
    char	*upperleft_tetro0;
	char	*upperleft_tetro1;
	*/

    all_buff = malloc(sizeof(char) * 52);
    
	/*
	upperleft_tetro0 = malloc(sizeof(char) * 52);
	upperleft_tetro1 = malloc(sizeof(char) * 52);
    */

	all_buff[0] = ".###\n..#.\n....\n....\n\n\0";
    all_buff[1] = "....\n.###\n..#.\n....\n\n\0";
	all_buff[2] = NULL;
   
	current = tetlst(all_buff);
	tetronum = 0;
	while (current != NULL)
	{
		printf("This is tetro %i: \n", tetronum);
		ft_putstr(current->tetro);
		printf("Length is: %i\n", current->length);
		printf("Width is: %i\n", current->width);
		current = current->next;
		tetronum++;
	}
	/*
	printf("This is vert[0]: %i\n", vert_pos(all_buff[1])[0]);
	printf("This is vert[1]: %i\n", vert_pos(all_buff[1])[1]);
	printf("This is hori[0]: %i\n", hori_pos(all_buff[1])[0]);
	printf("This is hori[1]: %i\n", hori_pos(all_buff[1])[1]);
	upperleft_tetro0 = move_upperleft(all_buff[0]);
    printf("This is tetro0 after trim: \n");
    ft_putstr(upperleft_tetro0);
	printf("\n");
	
	upperleft_tetro1 = move_upperleft(all_buff[1]);
    printf("This is tetro1 after trim: \n");
    ft_putstr(upperleft_tetro1);
	printf("\n");
	
	free(upperleft_tetro0);
	free(upperleft_tetro1);
	*/

    free(all_buff);
}
