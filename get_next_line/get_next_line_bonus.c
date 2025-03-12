/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsbai <amsbai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 22:38:14 by amsbai            #+#    #+#             */
/*   Updated: 2024/11/17 22:30:40 by amsbai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
//NULL === strinnewlinep ===> strinnewlinep
static char	*extract_line(char *str)
{
	size_t	i;
	char	*final;
	char	*line;
	size_t	a;

	final = ft_strchr(str, '\n');
	if (!final)
		a = ft_strlen(str);
	else
		a = final - str;
	i = 0;
	line = malloc(a + 1);
	if (!line)
		return (NULL);
	while (i < a)
	{
		line[i] = str[i];
		i++;
	}
	line[i] = 0;
	return (line);
}

static char	*startfree(char *str, char *start)
{
	char	*g;

	g = malloc(ft_strlen(str) + 1);
	if (!g)
		return (0);
	g[ft_strlen(str)] = 0;
	ft_memcpy (g, str, ft_strlen(str));
	free(start);
	return (g);
}

// BUFFER 10 by 10 && check for \n
static char	*find(char **start, int fd)
{
	char	*tobefree;
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytesread;
	char	*newline;

	while (1)
	{
		newline = ft_strchr (*start, '\n');
		if (newline)
			break ;
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread == 0)
			break ;
		if (bytesread == -1)
		{
			free(*start);
			*start = NULL;
			return (0);
		}
		buffer[bytesread] = 0;
		tobefree = *start;
		*start = ft_strjoin(*start, buffer);
		free (tobefree);
	}
	return (newline);
}

char	*get_next_line(int fd)
{
	static char	*start[10240];
	char		*extracted;
	char		*newlinep;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	newlinep = find(&start[fd], fd);
	extracted = extract_line(start[fd]);
	start[fd] = startfree(newlinep, start[fd]);
	if (extracted[0] == '\0')
	{
		free (start[fd]);
		free (extracted);
		start[fd] = 0;
		return (NULL);
	}
	return (extracted);
}

// void doop(int fd)
// {
// 	char *line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// }
// void ll()
// {
// 	system("leaks a.out");
// }
// #include <fcntl.h>
// int main()
// {
// 	//atexit(ll);
// 	int fd;
// 	int fd2 = open("fd2" , O_RDONLY);
// 	char *ln;
// 	fd = open("filetest", O_RDONLY);
// 	doop(fd);
// 	doop(fd2);
// 	doop(fd);
// 	doop(fd2);
// 	doop(fd);
// 	doop(fd2);
// }