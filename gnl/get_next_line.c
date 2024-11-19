/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:32:57 by rcaillie          #+#    #+#             */
/*   Updated: 2024/10/23 09:32:57 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

size_t	gnl_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*gnl_handle_read_error(char *buff, char *left_str)
{
	free(buff);
	free(left_str);
	return (NULL);
}

char	*gnl_read_to_left_str(int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!gnl_strchr(left_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
			return (gnl_handle_read_error(buff, left_str));
		buff[rd_bytes] = '\0';
		left_str = gnl_strjoin(left_str, buff);
		if (!left_str)
			return (gnl_handle_read_error(buff, left_str));
	}
	free(buff);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*left_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	left_str = gnl_read_to_left_str(fd, left_str);
	if (!left_str)
		return (NULL);
	line = gnl_get_line(left_str);
	left_str = gnl_new_left_str(left_str);
	return (line);
}
