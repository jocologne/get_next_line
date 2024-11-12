/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:39:48 by jcologne          #+#    #+#             */
/*   Updated: 2024/11/12 19:59:02 by jcologne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_buffer(int fd)
{
	char	*buffer;
	int		bytes_read;

	if (fd < 0)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));	
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	buffer[bytes_read] = '\0';
	return (buffer);
}

char *fill_line(char *line, int fd)
{
	char	*temp = get_buffer(fd);
	if (!line)
		line = ft_calloc(1, sizeof(char));
	while (1)
	{
		line = ft_strjoin(line, temp);
		if (ft_strchr(temp ,'\n'))
			break;
	}
	return (line);
}

#include <stdio.h>
#include <fcntl.h>
int main(void)
{
	char	*str;
	int fd = open("teste.txt", O_RDONLY);
	printf("%d\n", fd);
	str = fill_line(str, fd);
	printf("%s", str);
}

