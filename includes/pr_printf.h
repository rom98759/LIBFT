/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:16:01 by rcaillie          #+#    #+#             */
/*   Updated: 2024/11/19 22:16:01 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PR_PRINTF_H
# define PR_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef unsigned long int	t_uintptr;

int		pr_print_arg(char c, va_list args);
int		ft_printf(const char *format, ...);
char	*pr_strchr(const char *s, int c);
int		pr_strlen(const char *str);
char	*pr_strrev(char *str);
int		pr_numlen_base(t_uintptr nbr, int base);
char	*pr_itoa_base(t_uintptr nbr, int base, int is_upper);
char	*pr_itoa(int n);
int		pr_print_char(int c);
int		pr_print_string(char *str);
int		pr_print_pointer(t_uintptr address);
int		pr_print_int(int n);
int		pr_print_unsigned(unsigned int n);
int		pr_print_hex(unsigned int n, int upper);
char	*pr_hexa(unsigned int n, int upper);
int		pr_print_arg(char c, va_list args);

#endif
