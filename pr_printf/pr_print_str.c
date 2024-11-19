/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:15:45 by rcaillie          #+#    #+#             */
/*   Updated: 2024/11/19 22:15:45 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pr_printf.h"

int	pr_print_string(char *str)
{
	if (str == NULL)
		return (write(1, "(null)", 6));
	return (write(1, str, pr_strlen(str)));
}
