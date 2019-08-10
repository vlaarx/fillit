/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:40:48 by egiant            #+#    #+#             */
/*   Updated: 2019/05/01 15:42:48 by egiant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_vfile(char **lines, int linenum, int i, int k)
{
	int	j;

	if (linenum % 5 != 0)
		return (0);
	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
		{
			if (lines[i][j] != '.' && lines[i][j] != '#' && lines[i][j] != '\n'
					&& lines[i][j] != '\0')
				return (0);
			j++;
		}
		if (j != 4)
		{
			if (i == k)
				k = k + 5;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int		ft_touch(char *str, int i, int touch, int element)
{
	while (str[i])
	{
		if (str[i] == '#')
		{
			element++;
			if (i - 1 >= 0 && str[i - 1] == '#')
				touch++;
			if (i + 1 < 17 && str[i + 1] == '#')
				touch++;
			if (i - 4 >= 0 && str[i - 4] == '#')
				touch++;
			if (i + 4 < 17 && str[i + 4] == '#')
				touch++;
		}
		i++;
	}
	if (touch >= 6 && element == 4)
		return (1);
	else
		return (0);
}

int		ft_vtetram(char **lines, int figure)
{
	int		i;
	int		j;
	int		k;
	int		arrlen;
	char	array[17];

	i = 0;
	k = 4;
	while (figure-- > 0)
	{
		arrlen = 0;
		while (lines[i] && i != k)
		{
			j = 0;
			while (lines[i][j] != '\0')
				array[arrlen++] = lines[i][j++];
			i++;
		}
		array[arrlen] = '\0';
		if (!(ft_touch(array, 0, 0, 0)))
			return (0);
		i++;
		k = k + 5;
	}
	return (1);
}
