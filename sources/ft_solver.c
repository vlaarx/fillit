/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetra_solve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: screight <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 13:16:01 by screight          #+#    #+#             */
/*   Updated: 2019/05/01 16:08:21 by egiant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_sq_size(int tetr_num)
{
	int		size;
	int		a;

	a = 2;
	size = tetr_num * 4;
	while (a * a < size)
		a++;
	return (a);
}

char		**ft_make_square(int tetr_num)
{
	int		sq_side;
	int		i;
	int		count;
	char	**square;

	count = 0;
	sq_side = ft_sq_size(tetr_num);
	square = (char **)malloc(sizeof(char *) * (sq_side + 1));
	while (count < sq_side)
	{
		i = 0;
		square[count] = (char *)malloc(sizeof(char) * (sq_side + 1));
		while (i < sq_side)
			square[count][i++] = '.';
		square[count][i] = '\0';
		count++;
	}
	square[sq_side] = NULL;
	return (square);
}

char		**ft_sq_malloc(int sq_side)
{
	int		i;
	int		count;
	char	**square;

	count = 0;
	square = (char **)malloc(sizeof(char *) * (sq_side + 1));
	while (count < sq_side)
	{
		i = 0;
		square[count] = (char *)malloc(sizeof(char) * (sq_side + 1));
		while (i < sq_side)
			square[count][i++] = '.';
		square[count][i] = '\0';
		count++;
	}
	square[sq_side] = NULL;
	return (square);
}

void		ft_free_square(char **square, int sq_side)
{
	while (sq_side >= 0)
	{
		free(square[sq_side]);
		sq_side--;
	}
	free(square);
	square = NULL;
}

void		ft_solver(char *string, char **square, t_indx **tetra, int sq_side)
{
	int		ret;
	int		i;

	ret = 1;
	i = 0;
	while (ret != 0)
	{
		if ((ret = ft_replacer(string, square, tetra, sq_side)) == -1)
		{
			ft_free_square(square, sq_side);
			square = ft_sq_malloc(++sq_side);
		}
	}
	while (square[i])
	{
		ft_putendl(square[i]);
		i++;
	}
	ft_free_square(square, sq_side);
	while ((*tetra))
		ft_del_last_lst(tetra);
}