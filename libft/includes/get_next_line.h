/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: screight <screight@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:27:35 by screight          #+#    #+#             */
/*   Updated: 2019/08/10 15:03:31 by screight         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 10

int					get_next_line(const int fd, char **line);

typedef struct		s_lst
{
	char			*buf;
	int				lfd;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_str
{
	t_lst			*head;
	t_lst			*temp;
}					t_str;
#endif
