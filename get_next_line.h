/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajem <mnajem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 20:26:53 by mnajem            #+#    #+#             */
/*   Updated: 2025/08/28 19:56:41 by mnajem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char *get_next_line(int fd);
size_t ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst,  char *src, size_t size);
char	*ft_strdup( char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char  *s1, char  *s2);
char	*ft_strchr(const char *s, int c);


#endif