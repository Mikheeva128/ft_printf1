/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d15_d16_p_specifiers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olydden <olydden@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 19:03:38 by olydden           #+#    #+#             */
/*   Updated: 2020/08/10 09:53:17 by olydden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	p2_specifier(t_flags *p_t_flags, char **pointer, unsigned long long p)
{
	int	spaces;

	spaces = 0;
	if (p_t_flags->width && p)
		spaces = (p_t_flags->width - (ft_strlen(*pointer) + 2));
	else
		spaces = (p_t_flags->width - ft_strlen(*pointer));
	return (spaces);
}

int	p1_specifier(t_flags *p_t_flags, char **pointer, unsigned long long p,
					int spaces)
{
	int printed;
	int counter;

	printed = 0;
	counter = 0;
	if (p_t_flags->minus)
	{
		if (p)
			printed += ft_putstr("0x");
		printed += ft_putstr(*pointer);
		while (counter++ < spaces)
			printed += ft_putchar(' ');
	}
	else
	{
		while (counter++ < spaces)
			printed += ft_putchar(' ');
		if (p)
			printed += ft_putstr("0x");
		printed += ft_putstr(*pointer);
	}
	return (printed);
}

int	p_specifier(va_list ap, t_flags *p_t_flags)
{
	int					printed;
	char				*pointer;
	unsigned long long	p;
	int					spaces;

	printed = 0;
	pointer = NULL;
	spaces = 0;
	p = va_arg(ap, unsigned long long);
	if (p)
	{
		if (!(pointer = ft_itoa_base(p, 16)))
		{
			ft_free(pointer);
			return (-1);
		}
	}
	else
		pointer = "(nil)";
	spaces = p2_specifier(p_t_flags, &pointer, p);
	printed += p1_specifier(p_t_flags, &pointer, p, spaces);
	if (p)
		ft_free(pointer);
	return (printed);
}

int	d16_specifier(t_flags *p_t_flags, const char *format, int *i, int d)
{
	int printed;
	int spaces;
	int counter;

	printed = 0;
	spaces = 0;
	counter = 0;
	if ((p_t_flags->width && d != 0) || (p_t_flags->width &&
				format[*i - 1] != '.'))
		spaces = p_t_flags->width - ft_nbrlen(d);
	else
		spaces = p_t_flags->width;
	while (counter++ < spaces)
		printed += ft_putchar(' ');
	if (format[*i - 1] != '.' || d != 0)
	{
		ft_putnbr(d);
		printed += ft_nbrlen(d);
	}
	return (printed);
}

int	d15_specifier(t_flags *p_t_flags, int null, int d)
{
	int printed;
	int	spaces;
	int counter;

	printed = 0;
	spaces = 0;
	counter = 0;
	if ((p_t_flags->width && null > 0) ||
		(p_t_flags->precision == 0 &&
		null > 0) || d == 0)
		spaces = p_t_flags->width - p_t_flags->precision;
	else
		spaces = p_t_flags->width - ft_nbrlen(d);
	while (counter++ < spaces)
		printed += ft_putchar(' ');
	return (printed);
}
