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

char *remain(char * line)
{
    int end;
    int start;

    end = 0;
    start = 0;
    while(line[start] != '\n' && line[start])
        start++;
    end = start;
    while(line[end])
        end++;
    if(line[start] == '\n')
        start++;
    if(line[start])
        return(ft_substr(line, start, end - start));
    return NULL;
}

char *get_line(char * line)
{
    int end = 0;

    while(line[end] != '\n' && line[end])
        end++;
    if(line[end] == '\n')
        end++;
    return(ft_substr(line,0,end));
}

char *get_next_line(int fd)
{
    static char *s = NULL;
    char *buf;
    char *line = malloc(BUFFER_SIZE + 1);

    buf = malloc(BUFFER_SIZE + 1);
    if(s)
        line = ft_strdup(s);
    // int i = 0;
    while(1)
    {
        if(read(fd, buf, BUFFER_SIZE) == 0)
            break ;
        char *temp;
        temp = ft_strjoin(line,buf);
        free(line);
        line = temp;
        // printf("line_%d = %s\n",i, line );
        if(ft_strchr(line, '\n') != NULL)
            break;
        // i++;
    }
    s = remain(line);
    printf("s = %s\n",s);
    return(get_line(line));
}


int main(void) {
    int fd;

    fd = open("file.txt", O_RDONLY);
    if(fd == -1)
        return 0;
    int i = 0;
    while (i < 6)
    {
        printf("the line %i = %s", i ,get_next_line(fd));
        i++;
    }
    close(fd);
}
