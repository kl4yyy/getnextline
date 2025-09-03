/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajem <mnajem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 20:26:29 by mnajem            #+#    #+#             */
/*   Updated: 2025/09/02 21:31:07 by mnajem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_rem(char *rem)
{
	int		i;
	char	*n_rem;

	i = 0;
	if (!rem)
		return (NULL);
	while (rem[i] && rem[i] != '\n')
		i++;
	if (rem[i] == '\n')
		i++;
	if (!rem[0])
	{
		free(rem);
		return (NULL);
	}
	n_rem = ft_substr(rem, i, ft_strlen(rem) - i);
	free(rem);
	return (n_rem);
}

char	*ft_line(char *rem)
{
	int		i;
	char	*line;

	if (!rem)
		return (NULL);
	i = 0;
	while (rem[i] && rem[i] != '\n')
		i++;
	if (rem[i] == '\n')
		i++;
	line = ft_substr(rem, 0, i);
	return (line);
}

char	*ft_read(int fd, char *rem)
{
	char	*buff;
	int		bytes;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	bytes = 1;
	while ((!rem || !ft_strchr(rem, '\n')) && bytes > 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buff);
			free(rem);
			return (NULL);
		}
		buff[bytes] = '\0';
		rem = ft_strjoin(rem, buff);
	}
	free(buff);
	return (rem);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rem;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rem = ft_read(fd, rem);
	if (!rem)
		return (NULL);
	line = ft_line(rem);
	rem = ft_rem(rem);
	if (!line || !line[0])
	{
		free(line);
		return (NULL);
	}
	return (line);
}

// int	main(void)
// {
// 	int fd = open("t.txt", O_RDONLY);
// 	char *line;
// 	int i = 0;

// 	while ((line = get_next_line(fd)))
// 	{
// 		printf("Line %d: %s", i, line);
// 		free(line);
// 		i++;
// 	}

// 	close(fd);
// 	return (0);
// }