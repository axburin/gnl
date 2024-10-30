/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axburin- <axburin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:14:15 by axburin-          #+#    #+#             */
/*   Updated: 2024/10/30 17:35:23 by axburin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H 

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
size_t  ft_strlcpy(char *dst, const char *src, size_t size);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strdup(char *s);

# endif