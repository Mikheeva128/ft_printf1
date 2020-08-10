/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olydden <olydden@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 20:47:46 by olydden           #+#    #+#             */
/*   Updated: 2020/05/29 21:53:40 by olydden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	if (!(new = (t_list	*)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
		new->content = content;
	else
		new->content = NULL;
	new->next = NULL;
	return (new);
}
