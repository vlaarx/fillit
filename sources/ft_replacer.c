#include "fillit.h"

void		ft_put_erase_tetr(char *string, char **square, t_indx *tetra, int var)
{
	int		f;
	char	ch;
	int		i;
	int		j;
	int		s;

	ch = (var == -1 ? '.' : string[tetra->s - 1]);
	i = tetra->i;
	j = tetra->j;
	s = tetra->s;
	f = 4;
	while (f--)
	{
		if (string[s - 1] >= 65 && string[s - 1] <= 90)
			square[i][j] = ch;
		else if (string[s] - '0' >= 2)
		{
			j = j - (4 - (string[s] - '0'));
			square[++i][j] = ch;
		}
		else
			square[i][++j] = ch;
		s++;
	}
}

int			ft_tetra_can_place(char *string, char **square, t_indx *tetra, int count)
{
	int		i;
	int		j;
	int		s;

	i = tetra->i;
	j = tetra->j;
	s = tetra->s;
	while (count--)
	{
		if (string[s] - '0' >= 2 && !(string[s - 1] >= 65 && string[s - 1] <= 90))
		{
			if (!square[++i] || (j = j - (4 - (string[s] - '0'))) < 0 || square[i][j] != '.')
				return (-1);
		}
		else
		{
			if (string[s - 1] >= 65 && string[s - 1] <= 90)
				j--;
			if (!(square[i][++j]) || square[i][j] != '.')
				return (-1);
		}
		s++;
	}
	return (1);
}

int			ft_tetra_can_move(t_indx **tetra, int sq_side)
{
	if ((*tetra)->j < sq_side - 1)
		(*tetra)->j++;
	else if ((*tetra)->i < sq_side - 1)
	{
		(*tetra)->i++;
		(*tetra)->j = 0;
	}
	else
		return (-1);
	return (1);
}

int			ft_rec_tetra_del(char *string, char **square, t_indx **tetra, int sq_side)
{
	int		move_ret;

	move_ret = ft_tetra_can_move(tetra, sq_side);
	if (move_ret == -1 && (*tetra)->ch != 'A')
	{
		ft_del_last_lst(tetra);
		ft_put_erase_tetr(string, square, *tetra, -1);
		ft_rec_tetra_del(string, square, tetra, sq_side);
	}
	else if (move_ret == -1 && (*tetra)->ch == 'A')
	{
		(*tetra)->i = 0;
		(*tetra)->j = 0;
		return (-1);
	}
	return (1);
}

int			ft_replacer(char *string, char **square, t_indx **tetra, int sq_side)
{
	int		place_ret;

	if ((place_ret = ft_tetra_can_place(string, square, *tetra, 4)) == 1)
		ft_put_erase_tetr(string, square, *tetra, 1);
	if (place_ret == 1 && (string[(*tetra)->s + 4]) != '\0')
		ft_coord_list(tetra, string[(*tetra)->s + 4]);
	else if (place_ret == 1 && !(string[(*tetra)->s + 4]))
		return (0);
	else if (place_ret == -1)
	{
		if (ft_rec_tetra_del(string, square, tetra, sq_side) == -1)
			return (-1);
	}
	return (1);
}

