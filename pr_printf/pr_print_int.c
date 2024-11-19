/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:15:34 by rcaillie          #+#    #+#             */
/*   Updated: 2024/11/19 22:15:34 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pr_printf.h"

int	pr_print_int(int n)
{
	int		ret;
	char	*str;

	ret = 0;
	str = pr_itoa(n);
	if (str)
	{
		ret = write(1, str, pr_strlen(str));
		free(str);
	}
	else
		return (-1);
	return (ret);
}
