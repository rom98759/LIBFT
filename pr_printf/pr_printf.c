/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:15:54 by rcaillie          #+#    #+#             */
/*   Updated: 2024/11/19 22:15:54 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pr_printf.h"

static int	pr_is_corrupted(const char *format)
{
	int	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (1);
		}
		i++;
	}
	return (0);
}

int	pr_print_arg(char c, va_list args)
{
	if (c == 0)
		return (0);
	if (c == 'c')
		return (pr_print_char(va_arg(args, int)));
	if (c == 's')
		return (pr_print_string(va_arg(args, char *)));
	if (c == 'p')
		return (pr_print_pointer(va_arg(args, t_uintptr)));
	if (c == 'd' || c == 'i')
		return (pr_print_int(va_arg(args, int)));
	if (c == 'u')
		return (pr_print_unsigned(va_arg(args, unsigned int)));
	if (c == 'x')
		return (pr_print_hex(va_arg(args, unsigned int), 0));
	if (c == 'X')
		return (pr_print_hex(va_arg(args, unsigned int), 1));
	if (c == '%')
		return (write(1, "%", 1));
	else
	{
		write(1, "%", 1);
		write(1, &c, 1);
		return (2);
	}
	return (0);
}

static int	pr_parse_format(const char *format, va_list args)
{
	int		ret;
	int		i;

	ret = 0;
	i = 0;
	while (format[i])
	{
		if (ret < 0)
			return (-1);
		if (format[i] == '%')
		{
			i++;
			if (format[i] != '\0' && pr_strchr("cspdiuxX%", format[i]))
				ret += pr_print_arg(format[i], args);
			else
				return (-1);
		}
		else
			ret += write(1, &format[i], 1);
		i++;
	}
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;

	va_start(args, format);
	if (!format || pr_is_corrupted(format) == 1)
		return (-1);
	ret = pr_parse_format(format, args);
	va_end(args);
	return (ret);
}
