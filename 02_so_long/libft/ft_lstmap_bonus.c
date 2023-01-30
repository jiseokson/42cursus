/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:18:43 by jison             #+#    #+#             */
/*   Updated: 2022/11/12 16:56:21 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstmap_alloc_fail(t_list *lst, void (*del)(void *))
{
	ft_lstclear(&lst, del);
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*cur;
	t_list	*temp_new;

	if (!lst || !f || !del)
		return (0);
	ret = 0;
	cur = lst;
	while (cur)
	{
		temp_new = ft_lstnew((void *)0);
		if (!temp_new)
			return (ft_lstmap_alloc_fail(ret, del));
		temp_new->content = f(cur->content);
		ft_lstadd_back(&ret, temp_new);
		if (!temp_new->content)
			return (ft_lstmap_alloc_fail(ret, del));
		cur = cur->next;
	}
	return (ret);
}
