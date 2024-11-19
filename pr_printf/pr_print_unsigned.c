/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:15:50 by rcaillie          #+#    #+#             */
/*   Updated: 2024/11/19 22:15:50 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pr_printf.h"

int	pr_print_unsigned(unsigned int n)
{
	char	*str;
	int		len;

	str = pr_itoa_base((unsigned long)n, 10, 0);
	if (!str)
		return (-1);
	len = pr_print_string(str);
	free(str);
	return (len);
}
