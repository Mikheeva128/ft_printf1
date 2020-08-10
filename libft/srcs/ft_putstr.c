/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olydden <olydden@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 22:01:18 by olydden           #+#    #+#             */
/*   Updated: 2020/08/09 15:49:29 by olydden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char const *s)
{
	int printed;
	int	i;

	printed = 0;
	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			ft_putchar(s[i]);
			i++;
			printed++;
		}
	}
	return (printed);
}
