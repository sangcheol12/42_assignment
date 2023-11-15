/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangchep <sangchep@student@42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 01:59:09 by sangchep          #+#    #+#             */
/*   Updated: 2023/07/06 22:59:50 by sangchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *buf, char *save_point)
{
	int		cnt;
	char	*tp;

	cnt = 1;
	while (cnt)
	{
		cnt = read(fd, buf, BUFFER_SIZE);
		if (cnt == -1)
			return (NULL);
		else if (cnt == 0)
			break ;
		buf[cnt] = '\0';
		if (!save_point)
			save_point = ft_strjoin("", "");
		tp = save_point;
		save_point = ft_strjoin(tp, buf);
		if (!save_point)
			return (NULL);
		free(tp);
		tp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (save_point);
}

static char	*split_line(char *line)
{
	int		i;
	char	*res;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	res = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (res == NULL)
		return (NULL);
	if (res[0] == '\0')
	{
		free(res);
		res = NULL;
		return (NULL);
	}
	line[i + 1] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*save_point;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	line = read_line(fd, buf, save_point);
	free(buf);
	buf = NULL;
	if (line == NULL)
	{
		free(save_point);
		save_point = NULL;
		return (NULL);
	}
	save_point = split_line(line);
	return (line);
}

/*#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	int		fd;
	char	*line;

	fd = 0;
	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%p\n", line);
	printf("%s\n", line);

	line = get_next_line(fd);
	printf("%p\n", line);
	printf("%s\n", line);

	line = get_next_line(fd);
	printf("%p\n", line);
	printf("%s\n", line);

	line = get_next_line(fd);
	printf("%p\n", line);
	printf("%s\n", line);
	return (0);
}*/