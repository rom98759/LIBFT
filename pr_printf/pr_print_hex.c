/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:15:23 by rcaillie          #+#    #+#             */
/*   Updated: 2024/11/19 22:15:23 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pr_printf.h"

char	*pr_hexa(unsigned int n, int upper)
{
	char	*hex;
	int		count;
	char	*str;

	count = 0;
	if (upper)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	str = malloc(pr_numlen_base(n, 16) + 1);
	if (!str)
		return (0);
	if (n == 0)
		str[count++] = '0';
	while (n != 0)
	{
		str[count] = hex[n % 16];
		count++;
		n /= 16;
	}
	str[count] = '\0';
	pr_strrev(str);
	return (str);
}

int	pr_print_hex(unsigned int n, int upper)
{
	char	*str;
	int		ret;

	str = pr_hexa(n, upper);
	if (str == NULL)
		return (-1);
	ret = write(1, str, pr_strlen(str));
	free(str);
	return (ret);
}
