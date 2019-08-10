/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 11:06:17 by egiant            #+#    #+#             */
/*   Updated: 2019/05/01 15:17:08 by egiant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_linenum(char *filename)
{
	char	buff[546];
	int		linenum;
	int		i;
	int		ret;
	int		fd;

	i = 0;
	linenum = 0;
	fd = open(filename, O_RDONLY);
	ret = read(fd, buff, 545);
	if (ret == 0)
		return (0);
	buff[ret] = '\0';
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
			++linenum;
		++i;
	}
	ret = read(fd, buff, 545);
	close(fd);
	if (ret > 0)
		return (0);
	return (linenum + 1);
}

int		main(int argc, char *argv[])
{
	int		fd;
	int		linenum;

	if (argc == 2)
	{
		if (!(linenum = ft_linenum(argv[1])))
		{
			ft_putstr("error");
			return (0);
		}
		fd = open(argv[1], O_RDONLY);
		if (!(ft_fillit(fd, linenum, linenum / 5)))
			ft_putstr("error");
		close(fd);
	}
	else
		return (0);
}
