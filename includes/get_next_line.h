/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:33:24 by rcaillie          #+#    #+#             */
/*   Updated: 2024/10/23 09:33:24 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*gnl_strjoin(char *left_str, char *buff);
size_t	gnl_strlen(char *s);
char	*gnl_strchr(char *s, int c);
char	*gnl_get_line(char *left_str);
char	*gnl_new_left_str(char *left_str);

#endif
