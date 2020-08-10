/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olydden <olydden@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:20:51 by olydden           #+#    #+#             */
/*   Updated: 2020/08/10 09:56:30 by olydden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, int n)
{
	char	*dup;
	char	*dup_start;

	if (n < 0)
		return ((char *)s);
	if (!(dup = (char *)malloc(sizeof(char) * (n + 1))))
	{
		ft_free(dup);
		return (NULL);
	}
	dup_start = dup;
	while (n && *s)
	{
		*(dup++) = *(s++);
		n--;
	}
	*dup = '\0';
	return (dup_start);
}
