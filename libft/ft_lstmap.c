/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selibrah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 02:55:45 by selibrah          #+#    #+#             */
/*   Updated: 2019/05/19 00:55:11 by selibrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*dst;
	t_list	*hd;

	if (!lst || !f)
		return (NULL);
	dst = f(lst);
	hd = dst;
	while ((lst = lst->next))
	{
		if (dst == NULL)
			return (NULL);
		dst->next = f(lst);
		dst = dst->next;
	}
	return (hd);
}
