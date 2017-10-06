/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil_libft.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmacrae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 12:57:06 by cmacrae           #+#    #+#             */
/*   Updated: 2017/09/28 11:52:16 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIL_LIBFT_H
# define FIL_LIBFT_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct		s_list
{
	char			*maketet;
	int				length;
	int				width;
	struct s_list	*next;
}					t_list;

void				ft_bzero(void *s, size_t n);

void				*ft_memalloc(size_t size);

char				*ft_strnew(size_t size);

void				ft_putchar(char c);

void				ft_putstr(char const *s);

size_t              ft_strlen(char const *s);

char				*ft_fillmatrix(int fd);

int					ft_findbigsquare(int quan_tets);

#endif


















