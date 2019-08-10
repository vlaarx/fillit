/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:10:13 by egiant            #+#    #+#             */
/*   Updated: 2019/05/01 16:17:02 by egiant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
//# define BUFF_SIZE 	10
# include <fcntl.h>
# include <libft.h>

typedef struct			s_tetraminos
{
	struct s_tetraminos	*next;
	char				**fig;
}						t_tetr;

typedef struct			s_coords
{
	int					x;
	int					y;
}						t_coord;

typedef struct			s_indexes
{
	int					i;
	int					j;
	int					s;
	char				ch;
	struct s_indexes	*next;
}						t_indx;

void					ft_del_last_lst(t_indx **tetra);
int						ft_replacer(char *string, char **square, t_indx **tetra, int sq_side);
int						get_next_line(const int fd, char **line);
void					ft_solver(char *string, char **square, t_indx **tetra, int sq_side);
int						ft_fillit(int fd, int linenum, int figures);
void					ft_tetra_list(char **lines, t_tetr *lst);
int						ft_vtetram(char **lines, int figure);
int						ft_vfile(char **lines, int linenum, int i, int k);
char					**ft_make_square(int sq_side);
int						ft_sq_size(int sq_side);
void					ft_coord_list(t_indx **tetra, char letter);

#endif