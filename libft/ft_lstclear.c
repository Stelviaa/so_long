/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:24:21 by sforesti          #+#    #+#             */
/*   Updated: 2022/11/14 18:48:42 by sforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*l_bis;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		l_bis = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = l_bis;
	}
}
