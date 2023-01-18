/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:09:01 by ncortigi          #+#    #+#             */
/*   Updated: 2022/10/13 17:18:53 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*l_nuova;
	t_list	*nodo;

	l_nuova = NULL;
	while (lst)
	{
		nodo = ft_lstnew(f(lst->content));
		if (!nodo)
		{
			ft_lstclear(&(l_nuova), del);
			return (NULL);
		}
		ft_lstadd_back(&(l_nuova), nodo);
		lst = lst->next;
	}
	return (l_nuova);
}
