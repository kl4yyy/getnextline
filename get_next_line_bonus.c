/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajem <mnajem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 20:26:29 by mnajem            #+#    #+#             */
/*   Updated: 2025/09/02 01:00:00 by mnajem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char *ft_rem(char *rem)
{
    int i;
    char *n_rem;

    if (!rem)
        return (NULL);
    i = 0;
    while (rem[i] && rem[i] != '\n')
        i++;
    if (rem[i] == '\n')
        i++;
    if (!rem[i])
    {
        free(rem);
        return (NULL);
    }
    n_rem = ft_substr(rem, i, ft_strlen(rem) - i);
    free(rem);
    return (n_rem);
}

char *ft_line(char *rem)
{
    int i;
    char *line;

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

char *ft_read(int fd, char *rem)
{
    char *buff;
    int bytes;

    buff = malloc(BUFFER_SIZE + 1);
    if (!buff)
        return NULL;
    bytes = 1;
    while ((!rem || !ft_strchr(rem, '\n')) && bytes > 0)
    {
        bytes = read(fd, buff, BUFFER_SIZE);
        if (bytes < 0)
        {
            free(buff);
            free(rem);
            return NULL;
        }
        buff[bytes] = '\0';
        rem = ft_strjoin(rem, buff);
    }
    free(buff);
    return rem;
}

char *get_next_line(int fd)
{
    char *line;
    static char *rem[MAX_FD]; 

    if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
        return (NULL);

    rem[fd] = ft_read(fd, rem[fd]);
    if (!rem[fd])
        return (NULL);

    line = ft_line(rem[fd]);
    rem[fd] = ft_rem(rem[fd]);

    if (!line || !line[0])
    {
        free(line);
        return (NULL);
    }
    return line;
}

// int main(void)
// {
//     int fd1 = open("file1.txt", O_RDONLY);
//     int fd2 = open("file2.txt", O_RDONLY);
//     char *line1;
//     char *line2;

//     while ((line1 = get_next_line(fd1)) || (line2 = get_next_line(fd2)))
//     {
//         if (line1)
//         {
//             printf("fd1: %s", line1);
//             free(line1);
//         }
//         if (line2)
//         {
//             printf("fd2: %s", line2);
//             free(line2);
//         }
//     }

//     close(fd1);
//     close(fd2);
//     return 0;
// }