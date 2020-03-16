#include "fillit.h"

void			ft_x_t_coords(t_coord *point, char **lines, int num)
{
	int			i;
	int			j;

	i = 0;
	while (num-- > 0)
	{
		j = 0;
		while (lines[i][j] && lines[i][j] != '#')
			j++;
		if (lines[i][j] == '#')
		{
			point->x = i;
			break ;
		}
		i++;
	}
}

void			ft_y_t_coords(t_coord *point, char **lines, int num)
{
	int			i;
	int			j;
	int			help;

	j = 0;
	while (num-- > 0)
	{
		i = 0;
		help = 4;
		while (help-- > 0 && lines[i][j] != '#')
			i++;
		if (i < 4 && lines[i][j] == '#')
		{
			point->y = j;
			break ;
		}
		j++;
	}
}

t_coord			*ft_find_t_coord(char **lines)
{
	t_coord		*point;

	point = (t_coord *)malloc(sizeof(t_coord));
	ft_x_t_coords(point, lines, 4);
	ft_y_t_coords(point, lines, 4);
	return (point);
}

int				ft_replace_to_start(char **lines, t_tetr *lst, t_coord *point, char let)
{
	int			j;
	int			i;
	int			s;
	int			num;

	i = 0;
	num = 4 - point->x;
	s = point->y;
	while (num-- > 0)
	{
		j = 0;
		(lst->fig)[i] = (char*)malloc(sizeof(char) * 5);
		while (lines[point->x][point->y])
		{
			(lst->fig)[i][j++] = (lines[point->x][point->y] == '#'
					? let : lines[point->x][point->y]);
			point->y++;
		}
		while (j < 4)
			(lst->fig)[i][j++] = '.';
		(lst->fig)[i++][j] = '\0';
		point->x++;
		point->y = s;
	}
	return (i);
}

void			ft_tetra_list(char **lines, t_tetr *lst)
{
	t_coord		*point;
	static char	letter = 'A';
	int			i;
	int			j;

	point = ft_find_t_coord(lines);
	lst->fig = (char **)malloc(sizeof(char *) * 5);
	i = ft_replace_to_start(lines, lst, point, letter);
	while (i < 4)
	{
		(lst->fig)[i] = (char*)malloc(sizeof(char) * 5);
		j = 0;
		while (j < 4)
			(lst->fig)[i][j++] = '.';
		(lst->fig)[i][j] = '\0';
		i++;
	}
	letter++;
	(lst->fig)[i] = NULL;
	free(point);
}
