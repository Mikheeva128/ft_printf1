/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olydden <olydden@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 21:55:09 by olydden           #+#    #+#             */
/*   Updated: 2020/05/31 22:16:59 by olydden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		numstr(char const *s1, char c)
{
	int	comp;
	int	cles;

	comp = 0;
	cles = 0;
	if (*s1 == '\0')
		return (0);
	while (*s1 != '\0')
	{
		if (*s1 == c)
			cles = 0;
		else if (cles == 0)
		{
			cles = 1;
			comp++;
		}
		s1++;
	}
	return (comp);
}

static int		len_str(char const *s2, char c, int i)
{
	int	lenght;

	lenght = 0;
	while (s2[i] != c && s2[i] != '\0')
	{
		lenght++;
		i++;
	}
	return (lenght);
}

static char		**tofree(char const **total_str, int j)
{
	while (j > 0)
	{
		j--;
		free((void *)total_str[j]);
	}
	free(total_str);
	return (NULL);
}

static char		**affect(char const *s, char **total_str, char c, int num_strs)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < num_strs)
	{
		k = 0;
		while (s[i] == c)
			i++;
		total_str[j] = (char *)malloc(sizeof(char) * (len_str(s, c, i) + 1));
		if (total_str[j] == NULL)
			return (tofree((char const **)total_str, j));
		while (s[i] != '\0' && s[i] != c)
			total_str[j][k++] = s[i++];
		total_str[j][k] = '\0';
		j++;
	}
	total_str[j] = 0;
	return (total_str);
}

char			**ft_split(char const *s, char c)
{
	char	**total_str;
	int		num_strs;

	if (!s)
		return (NULL);
	num_strs = numstr(s, c);
	total_str = (char **)malloc(sizeof(char *) * (num_strs + 1));
	if (!total_str)
		return (NULL);
	return (affect(s, total_str, c, num_strs));
}
