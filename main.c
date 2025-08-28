#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif


char *remain(char * line )
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

char *line1(int fd)
{
    static char *s = NULL;
    char *buf;
    char *line = malloc(BUFFER_SIZE + 1);

    buf = malloc(BUFFER_SIZE + 1);
    if(s)
        line = ft_strdup(s);
    int i = 0;
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
        i++;
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
    printf("the line 1 = %s", line1(fd));
    printf("the line 2 = %s", line1(fd));
    printf("the line 3 = %s", line1(fd));
    printf("the line 4 = %s", line1(fd));

    close(fd);
}
