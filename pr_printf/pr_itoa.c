/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:15:05 by rcaillie          #+#    #+#             */
/*   Updated: 2024/11/19 22:15:05 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pr_printf.h"

char	*pr_itoa_base(t_uintptr nbr, int base, int is_upper)
{
	char	*str;
	int		len;
	char	*digits;

	if (is_upper)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	len = pr_numlen_base(nbr, base);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = digits[nbr % base];
		nbr /= base;
	}
	return (str);
}

char	*pr_itoa(int n)
{
	char	*str;
	int		len;
	long	num;

	num = (long)n;
	if (num < 0)
		len = pr_numlen_base(-num, 10) + 1;
	else
		len = pr_numlen_base(num, 10);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (--len >= (n < 0))
	{
		str[len] = '0' + (num % 10);
		num /= 10;
	}
	return (str);
}
