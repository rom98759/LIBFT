/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_miscellaneous.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:15:11 by rcaillie          #+#    #+#             */
/*   Updated: 2024/11/19 22:15:11 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pr_printf.h"

int	pr_numlen_base(t_uintptr nbr, int base)
{
	int	len;

	len = 1;
	while (nbr >= (unsigned long long)base)
	{
		nbr /= base;
		len++;
	}
	return (len);
}

int	pr_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*pr_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*pr_strrev(char *str)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = pr_strlen(str) - 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	return (str);
}
