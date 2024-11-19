/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:15:40 by rcaillie          #+#    #+#             */
/*   Updated: 2024/11/19 22:15:40 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pr_printf.h"

int	pr_print_pointer(t_uintptr address)
{
	char	*str;
	int		len;

	if (address == 0)
		return (pr_print_string("(nil)"));
	str = pr_itoa_base(address, 16, 0);
	if (!str)
		return (-1);
	len = pr_print_string("0x");
	len += pr_print_string(str);
	free(str);
	return (len);
}
