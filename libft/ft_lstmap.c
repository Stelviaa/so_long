/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:17:26 by sforesti          #+#    #+#             */
/*   Updated: 2022/12/05 11:07:11 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_bis;
	t_list	*lst_swap;

	(void)del;
	if (!lst || !del || !f)
		return (0);
	lst_bis = malloc(sizeof(t_list));
	lst_bis->content = f(lst->content);
	lst_swap = lst_bis;
	while (lst->next)
	{
		lst = lst->next;
		lst_bis->next = malloc(sizeof(t_list));
		lst_bis = lst_bis->next;
		lst_bis->content = f(lst->content);
	}
	lst_bis->next = 0;
	return (lst_swap);
}
