/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: screight <screight@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 21:19:59 by screight          #+#    #+#             */
/*   Updated: 2019/08/10 16:21:17 by screight         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		fd;
	int 	ret;

	fd = open("text", O_RDONLY);
	ret = 1;
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		printf("%s\n", line);
		printf("%d\n", ret);
	}
	printf("%d\n", ret);
	close(fd);
	return (0);
}
