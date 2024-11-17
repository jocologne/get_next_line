/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:39:48 by jcologne          #+#    #+#             */
/*   Updated: 2024/11/16 23:09:04 by jcologne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_buffer(int fd)
{
	char	*buffer;
	int		bytes_read;

	if (fd < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	return (buffer);
}

static void	sep(char *str, char **line, char **rest)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
	{
		*line = ft_substr(str, 0, i + 1);
		*rest = ft_strdup(str + i + 1);
	}
	else
	{
		*line = ft_strdup(str);
		*rest = NULL;
	}
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*result;
	char		*rest;
	char		*buffer;

	if (!temp)
		temp = "\0";
	while (!ft_strchr(temp, '\n'))
	{
		buffer = get_buffer(fd);
		if (!buffer)
			break ;
		temp = ft_strjoin(temp, buffer);
	}
	if (temp && *temp)
		sep(temp, &result, &rest);
	free(temp);
	temp = rest;
	return (result);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = malloc(len + 1 * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}

#include <stdio.h>
#include <fcntl.h>
int main(void)
{
	int i = 0;
	int linhas = 4;
	char	*str;
	int fd = open("teste.txt", O_RDONLY);
	while (i < linhas)
	{
		str = get_next_line(fd);
		printf("%s", str);
		i++;
	}
}