#include "fillit.h"

t_tetr		*ft_makelist(char **lines, int num)
{
	t_tetr	*lst;
	t_tetr	*new_lst;
	t_tetr	*head;

	if (!(lst = (t_tetr *)malloc(sizeof(t_tetr))))
		return (NULL);
	lst->next = NULL;
	head = lst;
	while (num-- > 0)
	{
		ft_tetra_list(lines, lst);
		if (num == 0)
			break ;
		if (!(new_lst = (t_tetr *)malloc(sizeof(t_tetr))))
			return (NULL);
		new_lst->next = NULL;
		lst->next = new_lst;
		lines = (lines + 5);
		lst = lst->next;
	}
	return (head);
}

int				ft_f(char sym, char **str, int j, int s)
{
	if (s == -1)
	{
		**str = sym;
		(*str)++;
		**str = j + '0';
		(*str)++;
	}
	else
	{
		**str = (s + 1) + '0';
		(*str)++;
	}
	return (0);
}

void			ft_get_string(char *str, t_tetr *lst, int i, int s)
{
	int			j;
	int			help;

	while (lst)
	{
		help = 0;
		while (lst->fig[i])
		{
			j = 0;
			while ((lst->fig)[i][j] && help < 4)
			{
				if ((lst->fig)[i][j] >= 65 && (lst->fig)[i][j] <= 90)
					s = ((help == 0) ? ft_f((lst->fig)[i][j], &str, j, -1) :
							ft_f((lst->fig)[i][j], &str, j, s));
				else if (help-- != 0)
					s++;
				j++;
				help++;
			}
			i++;
		}
		lst = lst->next;
		i = 0;
	}
	*str = '\0';
}

void			ft_free_all(t_tetr *begin, char **lines, char *string)
{
	t_tetr		*tmp;
	int			i;
	int			j;

	i = 0;
	while (begin)
	{
		j = 0;
		while (begin->fig[j])
			free(begin->fig[j++]);
		free(begin->fig);
		tmp = begin->next;
		free(begin);
		begin = tmp;
	}
	while (lines[i])
	{
		free(lines[i]);
		i++;
	}
	free(lines);
	free(string);
}

int				ft_fillit(int fd, int linenum, int figures)
{
	char		**lines;
	char		*string;
	int			i;
	t_tetr		*begin;
	t_indx		*tetra;

	tetra = NULL;
	ft_coord_list(&tetra, 'A');
	i = 0;
	if (!(lines = (char **)malloc(sizeof(char *) * (linenum + 1))))
		return (0);
	while (get_next_line(fd, &lines[i]) == 1)
		i++;
	lines[i] = 0;
	if (!(ft_vfile(lines, linenum, 0, 4)) || !(ft_vtetram(lines, figures)))
		return (0);
	begin = ft_makelist((lines), figures);
	if (!begin)
		return (0);
	string = (char *)malloc(sizeof(char) * (figures + (figures * 4) + 1));
	ft_get_string(string, begin, 0, 0);
	ft_solver(string, ft_make_square(figures), &tetra, ft_sq_size(figures));
	ft_free_all(begin, lines, string);
	begin = NULL;
	return (1);
}
