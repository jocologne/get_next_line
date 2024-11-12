/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:42:51 by jcologne          #+#    #+#             */
/*   Updated: 2024/11/12 19:31:54 by jcologne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) +1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		str[j] = s2[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

void	*ft_calloc(size_t nmemb, size_t size)
{

	void			*result;
	unsigned char	*ptr;
	size_t			i;

	if ((nmemb != 0 && size) > ((size_t)-1) / nmemb)
		return (NULL);
	result = malloc(size * nmemb);
	if (!result)
		return (NULL);
	ptr = (unsigned char *)result;
	i = 0;
	while (i < size * nmemb)
		ptr[i++] = 0;
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	const char	*tmp;

	tmp = s;
	while (*tmp != '\0')
	{
		if (*tmp == (char)c)
			return ((char *)tmp);
		tmp++;
	}
	if ((char)c == '\0')
		return ((char *)tmp);
	return (NULL);
}