/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axburin- <axburin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:08:43 by axburin-          #+#    #+#             */
/*   Updated: 2024/10/30 17:37:16 by axburin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *s)
{
	int	i;

	i = 0;
	while(s[i])
		i++;
	return(i);
}
char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*dst;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dst = malloc(s1_len + s2_len + 1);
	if (!dst)
	{
		return (NULL);
	}
	ft_strlcpy(dst, s1, s1_len + 1);
	ft_strlcpy(dst + s1_len, s2, s2_len + 1);
	return (dst);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ps;
	unsigned int	i;

	ps = s;
	i = 0;
	while (i < n)
	{
		ps[i] = (unsigned char) c;
		i++;
	}
	return (s);
}
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned const char		*s;
	unsigned char			*d;
	unsigned int			i;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d < s)
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	if (d > s)
	{
		i = n;
		while (i > 0)
		{
			d[i - 1] = s[i - 1];
			i--;
		}
	}
	return (d);
}
char	*ft_strdup(char *s)
{
	char	*ptr;
	size_t	size;

	size = ft_strlen(s);
	ptr = malloc((size + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s, size + 1);
	return (ptr);
}
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != '\0')
	{
		while (src[i] != '\0' && i < (size -1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}
char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		else
			i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}
char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	max_len;
	char	*ptr;

	if ((!s))
		return (NULL);
	if (start >= ft_strlen(s) || (ft_strlen(s) == 0))
	{
		ptr = calloc(1, 1);
		return (ptr);
	}
	max_len = ft_strlen(s) - start;
	if (len > max_len)
		len = max_len;
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s + start, len + 1);
	return (ptr);
}