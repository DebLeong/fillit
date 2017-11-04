/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmacrae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 12:57:06 by cmacrae           #+#    #+#             */
/*   Updated: 2017/11/04 11:59:00 by dleong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_list
{
	char			*tetro;
	char			letter;
	int				length;
	int				width;
	int				total_width;
	struct s_list	*next;
}					t_list;

void				ft_bzero(char *s, size_t n);
char				*ft_bzboard(char *s, size_t n);
void				*ft_memalloc(size_t size);
char				*ft_strnew(size_t size);
void				ft_putstr(char const *s);
size_t				ft_strlen(char const *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strdup(const char *s1);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
void				*ft_memalloc(size_t size);
int					ft_isalpha(int c);
char				**ft_maketet(int fd);
int					ft_count_tetro(char **all_buff);
int					ft_findbigsquare(int tet_quan);
int					read_file(char *argv);
void				solve(int fd);
int					check_tetro_char(char *string, int size);
int					ft_checkconnection(char *buf, int size);
int					test_pos(t_list *tetlst, char *board, int b_len, int b_pos);
int					place_tet(t_list *tetlst, char *board, int b_len,\
						int b_pos);
void				del_tet(t_list *tetlst, char *board, int b_len, int b_pos);
int					recursive_solver(t_list *tetlst, char *board, int b_len, \
						int b_pos);
t_list				*tetlst(char **all_buff);
int					ft_aroundcheck(char *buf);
int					ft_checkmore(char *buf);
int					ft_checkvalidity(char *buf);
int					ft_onepiece(int fd);

#endif
