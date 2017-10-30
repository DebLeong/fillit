/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil_libft.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmacrae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 12:57:06 by cmacrae           #+#    #+#             */
/*   Updated: 2017/10/29 18:04:40 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIL_LIBFT_H
# define FIL_LIBFT_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

typedef struct		s_list
{
	char			*tetro;
	char			letter;
	int				length;
	int				width;
	int				tetro_len;
	struct s_list	*next;
}					t_list;

void				ft_bzero(char *s, size_t n);
char				*ft_bzboard(char *s, size_t n);
void				*ft_memalloc(size_t size);
char				*ft_strnew(size_t size);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
size_t				ft_strlen(char const *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strdup(const char *s1);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_isalpha(int c);
void				*ft_memalloc(size_t size);
char				*ft_fillmatrix(int fd);
char				**ft_maketet(int fd);
int					ft_count_tetro(char **all_buff);
int					ft_findbigsquare(int tet_quan);
int					test_pos(t_list *tetlst, char *board, int b_len, int b_pos);
int					place_tet(t_list *tetlst, char *board, int b_len,\
						int b_pos);
void				del_tet(t_list *tetlst, char *board, int b_len, int b_pos);
int					recursive_solver(t_list *tetlst, char *board, int b_len, \
						int b_pos);
t_list				*tetlst(char **all_buff);

#endif
