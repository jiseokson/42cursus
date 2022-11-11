/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jison <jison@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 22:18:43 by jison             #+#    #+#             */
/*   Updated: 2022/11/11 12:49:20 by jison            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*cur;
	t_list	*temp_new;

	ret = 0;
	cur = lst;
	while (cur)
	{
		temp_new = ft_lstnew((void *)0);
		if (!temp_new)
		{
			ft_lstclear(&ret, del);
			return (0);
		}
		temp_new->content = f(cur->content);
		if (!temp_new->content)
		{
			ft_lstclear(&ret, del);
			free(temp_new);
			return (0);
		}
		ft_lstadd_back(&ret, temp_new);
		cur = cur->next;
	}
	return (ret);
}
