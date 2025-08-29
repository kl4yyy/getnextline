/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajem <mnajem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 20:26:29 by mnajem            #+#    #+#             */
/*   Updated: 2025/08/28 20:03:52 by mnajem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_rem(char *rem)
{
    int i = 0;
    char *n_rem;

    if (!rem)
        return NULL;
    while(rem[i] && rem[i] != '\n')
        i++;
    if (rem[i] == '\n')
        i++;
    if(!rem[i])
    {
        free(rem);
        return NULL;
    }
    n_rem = ft_substr(rem , i, ft_strlen(rem) - i);
    free (rem);
    return n_rem;
}

char *ft_line(char *rem)
{
    int i = 0;
    char *line;

    if (!rem)
        return NULL;
    while(rem[i] && rem[i] != '\n')
        i++;
    if (rem[i] =='\n')
        i++;
    line = ft_substr(rem,0,i);
    return line;
}

char *ft_read (int fd ,char *rem)
{
    char *buff;
    int i;
    
    buff = malloc(BUFFER_SIZE+1);
    if(!buff)
        return NULL;
    i = 1;
    while((!rem || !ft_strchr(rem,'\n')) && i > 0)
    {
        i = read(fd,buff,BUFFER_SIZE);
        if(i < 0)
        {
            free(buff);
            free(rem);
            return NULL;
        }
        buff[i] = '\0';
        rem = ft_strjoin(rem,buff);
    }
    free(buff);
    return rem;
}

char *get_next_line(int fd)
{
    char *line;
    static char *rem;
    
    if(fd < 0 || BUFFER_SIZE <= 0)
        return 0;
    rem = ft_read(fd,rem);
    if (!rem)
        return NULL;
    line = ft_line(rem);
    rem = ft_rem(rem);
    if(!line[0])
    {
        free(line);
        return NULL;
    }
    return line;
    
}

// int main(void)
// {
//     int fd = open("file.txt", O_RDONLY);
//     char *line;
//     int i = 0;

//     if (fd < 0)
//     {
//         perror("open");
//         return 1;
//     }

//     while ((line = get_next_line(fd)))
//     {
//         printf("Line %d: %s", i, line); // note: line already includes '\n' if present
//         free(line);
//         i++;
//     }

//     close(fd);
//     return 0;
// }

