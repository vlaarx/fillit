#include "get_next_line.h"

int		checkerror(int fd)
{
	char	buff[BUFF_SIZE + 1];

	if (fd < 0 || read(fd, buff, 0) < 0)
		return (-1);
	else
		return (1);
}

void	saveline(char *str, char **line)
{
	int i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		++i;
	*line = ft_strnew(i);
	ft_strncpy((*line), str, i);
}

char	*readline(int fd)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];
	char	*str;
	char	*secondstr;

	ret = read(fd, buff, BUFF_SIZE);
	buff[ret] = '\0';
	if (!(str = ft_strdup(buff)))
		return (0);
	while (ret > 0)
	{
		if (ft_strchr(str, '\n'))
			break ;
		ret = read(fd, buff, BUFF_SIZE);
		buff[ret] = '\0';
		if (!(secondstr = ft_strjoin(str, buff)))
			return (0);
		free(str);
		str = secondstr;
	}
	return (str);
}

int		get_next_line(const int fd, char **line)
{
	char			*ptr;
	char			*str;
	static char		*remainder;

	if (checkerror(fd) == -1 || !(str = readline(fd)) || !line)
		return (-1);
	*line = NULL;
	if (remainder)
	{
		ptr = str;
		(str[0] == '\0') ? (str = ft_strdup(remainder)) :
			(str = ft_strjoin(remainder, str));
		free(ptr);
		free(remainder);
		remainder = NULL;
	}
	ptr = ft_strchr(str, '\n');
	if (ptr)
		remainder = ft_strdup(ptr + 1);
	saveline(str, line);
	free(str);
	if ((ft_strlen(*line) == 0) && ptr == NULL)
		ft_strdel(line);
	return ((*line == NULL && ptr == NULL) ? 0 : 1);
}
