/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axburin- <axburin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:48:08 by axburin-          #+#    #+#             */
/*   Updated: 2024/10/30 18:05:41 by axburin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t bytes_read;
	char *buf;
	char *cpy;
	char *new_pose;
	static char *tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if(!buf)
		return (NULL);
	cpy = malloc(1);
	if (!cpy) 
	{
		free(buf);
		return (NULL);
	}
	cpy[0] = '\0';
	while((bytes_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{		
		buf[bytes_read] = '\0';
		new_pose = ft_strchr(buf, '\n');
		if(new_pose != NULL)
		{
			*new_pose = '\0';
			tmp = cpy;
			cpy = ft_strjoin(tmp, buf);
			free(tmp);
			tmp = cpy;
			cpy = ft_strjoin(tmp, "\n");
			free(tmp);
			break;
		}
		tmp = cpy;
		cpy = ft_strjoin(tmp, buf);
		free(tmp);
	}
	free(buf);
	if (bytes_read < 0 || (bytes_read == 0 && cpy[0] == '\0'))
	{
		free(cpy);
		return (NULL);
	}
	tmp = NULL;
	return(cpy);
}
